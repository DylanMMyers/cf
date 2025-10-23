#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\grid_paths.exe

int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n, vector<int> (n, 0));
    if (v[n - 1][n - 1] == '.') dp[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (j > 0) {
                if (v[i][j - 1] == '.') dp[i][j - 1] = (dp[i][j - 1] + dp[i][j]) % MOD;
            }
            if (i > 0) {
                if (v[i - 1][j] == '.') dp[i - 1][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
            }
        }
    }
    cout << dp[0][0] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
}