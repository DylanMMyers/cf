#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\money_sums.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    // 2 2 4 5
    // 2 -> 1
    // 2 2 -> 2
    // 2 3 -> 3
    // 2 2 3 -> 5
    // 2 3 5 -> 3 + 2 + 1
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j]; // equals prev, if we could/couldn't reach it at some point before we initially have the same state
            int idx = j - v[i - 1]; // can we reach our current number using only numbers up to idx i?
            if (idx >= 0) {
                if (dp[i - 1][idx]) dp[i][j] = 1;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= sum; i++) {
        if (dp[n][i]) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << ' ';
    }
}