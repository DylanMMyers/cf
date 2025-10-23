#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    ll MOD = 1e9 + 7;
    while (tt--) {
        ll n, k; cin >> n >> k;
        vector<pair<ll,ll>> v(k); for (ll i = 0; i < k; i++) cin >> v[i].first >> v[i].second;
        ll dm = 0, ndm = 0; // diag move, non diag move
        for (ll i = 0; i < k; i++) {
            dm += (v[i].first == v[i].second);
            ndm += (v[i].first != v[i].second);
        }
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (ll i = 2; i <= n - dm - (2 * ndm); i++) {
            dp[i] = (dp[i - 1] + (2ll * (i - 1) * dp[i - 2]) % MOD) % MOD;
        }
        cout << dp[n - dm - (2 * ndm)] << "\n";     
    }
}