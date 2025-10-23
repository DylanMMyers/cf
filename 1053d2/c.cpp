#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> v[i];
        // brute force to check observation
        vector<ll> pse(2 * n + 1, 0), pso(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; i++) {
            pso[i] = pso[i - 1] + (i % 2 ? -1 * v[i - 1] : v[i - 1]);
            pse[i] = pse[i - 1] + (i % 2 ? v[i - 1] : -1 * v[i - 1]);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) ans += v[2 * n - i] - v[i - 1];
            if (i % 2) cout << ans + (pse[2 * n - i] - pse[i]) << ' ';
            else cout << ans + (pso[2 * n - i] - pso[i]) << ' ';
        }
        cout << "\n";
    }
}