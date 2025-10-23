#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;
        if (m < n || m > (n * (n + 1)) / 2) {
            cout << "-1\n";
            continue;
        }
        else {
            ll parent = 1, currscore = n;
            while (currscore < m) {
                parent++;
                currscore += n - parent + 1;
            }
            vector<ll> parents(n + 1, parent);
            ll currnode = parent + 1; // the node we will try move if we need to, starting with the min after the parent (most flexibility)
            while (currscore > m) {
                // we can assume we can move down the node because if we couldnt, 1 would already be the parent and we've decided this is not possible
                ll newparent = 1;
                while (currscore - (parent - newparent) < m) {
                    // this loop only actually happens when we are on the final node
                    newparent++;
                }
                currscore -= parents[currnode] - newparent;
                parents[currnode] = newparent;
                currnode++;
            }
            cout << parent << "\n";
            for (ll i = 1; i <= n; i++) {
                if (i == parent) continue;
                cout << parents[i] << ' ' << i << '\n';
            }
        }
    }
}