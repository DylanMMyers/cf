#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\shipping_company.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + c[j][i]);
        }
    }
    cout << dp[n - 1] << "\n";
}