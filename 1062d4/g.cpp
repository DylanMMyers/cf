#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\g.exe
// g++ g.cpp -o g

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n + 1), c(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> c[i];
        vector<ll> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            ll curr = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] <= a[i]) {
                    dp[i] = min(dp[i], dp[j] + curr);
                }
                curr += c[j];
            }
        }
        ll ans = LLONG_MAX, curr = 0;
        for (int i = n; i >= 0; i--) {
            ans = min(ans, dp[i] + curr);
            curr += c[i];
        }
        cout << ans << "\n";
    }
}