#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\collecting_candy.exe
// g++ collecting_candy.cpp -o collecting_candy

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> c(n), k(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> k[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, 0)); // dp[i] tracks the best score up to i if we use the current house, [i][0] if we dont trick-or-treat, [i][1] = if use k, [i][2] = if use c
    if (k[0] != -1) {
        dp[1][1] = k[0];
        dp[1][2] = c[0];
    }
    else {
        dp[1][1] = c[0];
        dp[1][2] = c[0];
    }
    for (int i = 2; i <= n; i++) {
        if (k[i - 1] == -1 && k[i - 2] == -1) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]) + c[i];
        }
        else if (k[i - 1] == -1 && k[i - 2] != -1) {
            dp[i][0] = 
        }
        else if (k[i - 1] != -1 && k[i - 2] == -1) {
            
        }
        else if (k[i - 1] 1= -1 && k[i - 2] 1= -1) {
            
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}