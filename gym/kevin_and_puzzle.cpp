#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\kevin_and_puzzle.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    int MOD = 998244353;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        // need to determine who can be a liar or not
        vector<vector<int>> dp(n, vector<int>(2, 0)); // dp[i][0] if i is liar, dp[i][1] if telling truth
        dp[0][0] = 1;
        dp[0][1] = (v[0] == 0);
        if (n == 1) {
            cout << dp[0][0] + dp[0][1] << "\n";
            continue;
        }
        for (int i = 1; i < n; i++) {
            
        }
        cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << "\n";
    }
}