#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, c; cin >> n >> c;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll curr = 0, idx = -1, best = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        curr += v[i];
        ll flag = 0ll;
        if ((curr + 1) % c) flag = 1ll;
        if ((curr + 1) / c + flag < best && (curr + 1) / c + flag < n - i + 1) {
            idx = i;
            best = (curr + 1) / c + flag;
        }
        curr = max(0ll, curr - c);
    }
    if (idx == -1) cout << "impossible";
    else cout << idx;
}