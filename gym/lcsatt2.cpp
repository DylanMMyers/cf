#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\lcsatt2.cpp.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = a[0] == b[0];
    for (int i = 1; i < n; i++) dp[i][0] = max(dp[i - 1][0], (int)(a[i] == b[0]));
    for (int i = 1; i < m; i++) dp[0][i] = max(dp[0][i - 1], (int)(a[0] == b[i]));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int x = n - 1, y = m - 1;
    vector<int> res;
    while (x && y) {
        if (dp[x - 1][y] == dp[x][y]) x--;
        else if (dp[x][y - 1] == dp[x][y]) y--;
        else {
            res.push_back(a[x]);
            x--;
            y--;
        }
    }
    if (dp[x][y] == 1) res.push_back(a[x]);
    cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " \n"[!i];
}

// we can say that if the first elements equal each other, we should use them
// from here, we can say that if we consider some later subsequence of X or Y, if we already had an earlier element which is equal we should use it
// so, we can iteratively define the 2d arrays first row/column to be if there has been a common element or if the current element is common with the first
// char of X or Y respectively
// from there, we can say that if a character is common, we should try to use this character (try all combinations of using this character, if its optimal we
// will use it in our answer) so we use the previous permutation (dp[i - 1][j - 1])
// and for every other element, we just take the current best subsequence (dp[i - 1][j], dp[i][j - 1])
// then, when we reach dp[n][m] we can say we have found the lcs