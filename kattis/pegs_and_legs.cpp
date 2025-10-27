#include <bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;
// g++ pegs_and_legs.cpp -o pegs_and_legs
// Get-Content t.txt | .\pegs_and_legs.exe

// treat it like a dag
// topo sort
// start from non-leg, lowest peg nodes and compute their ev based on E(l), E(r)
// work until drop nodes
// once we compute all the nodes, iter through drop nodes and select node with highest ev

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, p; cin >> l >> p;
    vector<ld> legs(l);
    vector<pair<ld,ld>> odds(p), pegs(p);
    for (int i = 0; i < l; i++) cin >> legs[i];
    for (int i = 0; i < p; i++) {
        cin >> odds[i].first >> odds[i].second >> pegs[i].first >> pegs[i].second;
        pegs[i].first--;
        pegs[i].second--;
    }
    vector<int> isDrop(l + p, 0);
    vector<ld> ev(l + p, 0.0), evstuck(l + p, 0.0);
    for (int i = 0; i < l; i++) {
        ev[i] = legs[i];
        evstuck[i] = (ld)0.0;
    }
    for (int i = l; i < l + p; i++) {
        int u = i;
        ld a = pegs[u - l].first, b = pegs[u - l].second;
        isDrop[a] = isDrop[b] = 1;
        ev[u] = ev[a] * odds[u - l].first + ev[b] * odds[u - l].second;
        evstuck[u] = evstuck[a] * odds[u - l].first + evstuck[b] * odds[u - l].second + (ld)1 - odds[u - l].first - odds[u - l].second;
    }
    ld ans = 0.0;
    for (int i = 0; i < l + p; i++) {
        if (!isDrop[i]) {
            ev[i] /= (ld)1 - evstuck[i];
            ans = max(ans, ev[i]);
        }
    }
    cout << setprecision(15) << ans;
}