#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\dice_combinations.exe

int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 6, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i - 1 > -1) dp[i] = (dp[i] + dp[i - 1]) % MOD;
        if (i - 2 > -1) dp[i] = (dp[i] + dp[i - 2]) % MOD;
        if (i - 3 > -1) dp[i] = (dp[i] + dp[i - 3]) % MOD;
        if (i - 4 > -1) dp[i] = (dp[i] + dp[i - 4]) % MOD;
        if (i - 5 > -1) dp[i] = (dp[i] + dp[i - 5]) % MOD;
        if (i - 6 > -1) dp[i] = (dp[i] + dp[i - 6]) % MOD;

    }
    cout << dp[n] << "\n";
}