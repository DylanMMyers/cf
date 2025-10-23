#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int MOD = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> b(n + 1); for (int i = 1; i <= n; i++) cin >> b[i];
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // 0 not swapped, 1 swapped
        dp[0][1] = 1; // swap empty subset
        for (int i = 1; i <= n; i++) {
            if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) {
                // none swapped
                dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
            }
            if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) {
                // curr swapped
                dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
            }
            if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) {
                // prev swapped
                dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
            }
            if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) {
                // both swapped
                dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
            }
        }
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }
}