#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\three_strings.exe

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    
    int n = a.length(), m = b.length();
    vector<vector<int>> dp (n + 1, (vector<int> (m + 1, INT_MAX)));
    
    // initalize
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = dp[i][0] + (c[i] != a[i]); // if its true (they do not equal) we add one to the count
    }
    for (int i = 0; i < m; i++) {
        dp[0][i + 1] = dp[0][i] + (c[i] != b[i]); // same as above
    }

    // compute
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j] + (c[i + j - 1] != a[i - 1]), dp[i][j - 1] + (c[i + j - 1] != b[j - 1]));
            // we check if the element to the left or above is more effective in minimizing the change (we select the best letter to add)
        }
    }

    cout << dp[n][m] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}