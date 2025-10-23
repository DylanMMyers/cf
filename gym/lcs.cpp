#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\lcs.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        // we just 2d dp this
        // the state can simply just be the length of the lcs up to that point
        // then maybe assign another pointer value to the prev value it got this from
        // the alternative is just storing the set, but this is O(n^3) vs keeping it O(n^2) for memory so pointers to prev is better
        // time will be O(n^2)
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = a[0] == b[0];
        for (int i = 1; i < n; i++) dp[i][0] = max(dp[i - 1][0], (int)(a[i] == b[0]));
        for (int i = 1; i < m; i++) dp[0][i] = max(dp[0][i - 1], (int)(a[0] == b[i]));
        // dp is now initalized to where the base cases are 1 or 0 (if the chars match)
        // now we can just iterate through all, update pointer to idx
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[n - 1][m - 1] << "\n";
        vector<int> perm;
        int x = n - 1, y = m - 1;
        while (x > 0 && y > 0) {
            if (dp[x - 1][y] == dp[x][y]) x--;
            else if (dp[x][y - 1] == dp[x][y]) y--;
            else {
                perm.push_back(b[y]);
                x--;
                y--;
                continue;
            }
        }
        if (dp[x][y] == 1) perm.push_back(b[y]);
        for (int i = perm.size() - 1; i >= 0; i--) {
            cout << perm[i] << ' ';
        }
    }
}