#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\aggie_games.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i]; // home
    for (int i = 0; i < n; i++) cin >> b[i]; // away
    vector<vector<int>> dp(n, vector<int>(2, 0)); // dp[i][0] = home, dp[i][1] = away
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1] + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
}