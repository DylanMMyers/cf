#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\forbidden_difference.exe
// g++ forbidden_difference.cpp -o forbidden_difference

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d; cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mx = *max_element(v.begin(), v.end());
    vector<int> count(mx + 1, 0);
    for (int i = 0; i < n; i++) {
        count[v[i]]++;
    }
    int ans = 0;
    if (!d) {
        for (int i = 0; i <= mx; i++) {
            if (count[i]) {
                ans += count[i] - 1;
            }
        }
        cout << ans;
        return 0;
    }
    vector<vector<int>> dp(mx + 1, vector<int>(2, 0)); // 0 if keep, 1 if remove
    for (int i = 0; i <= mx; i++) {
        if (i < d || !count[i]) {
            dp[i][0] = 0;
            dp[i][1] = count[i];
            continue;
        }
        if (count[i] && !count[i - d]) {
            // first element in a chain (chain may be of size 1)
            dp[i][0] = 0;
            dp[i][1] = count[i];
        }
        else {
            // some element later in the chain
            dp[i][0] = dp[i - d][1];
            dp[i][1] = min(dp[i - d][0], dp[i - d][1]) + count[i];
        }
    }
    // for each chain, need to find final element in it and take its min
    for (int i = 0; i <= mx; i++) {
        if (i + d <= mx) {
            if (count[i] && !count[i + d]) ans += min(dp[i][0], dp[i][1]);
        }
        else if (count[i]) {
            ans += min(dp[i][0], dp[i][1]);
        }
    }
    cout << ans;
} 