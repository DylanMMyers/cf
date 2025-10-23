#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\least_round.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) v[i][j] = 1;
            else if (v[i][j] == 5) v[i][j] = 1;
            else v[i][j] = 0;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = v[0][0];
    for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + v[i][0];
    for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + v[0][i];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    int x = n - 1, y = n - 1;
    string res = "";
    while (x && y) {
        if (dp[x - 1][y] < dp[x][y - 1]) {
            res += 'D';
            x--;
        }
        else {
            res += 'R';
            y--;
        }
    }
    while (x) {
        res += 'D';
        x--;
    }
    while (y) {
        res += 'R';
        y--;
    }
    reverse(res.begin(), res.end());
    cout << res;
} 