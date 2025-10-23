#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\minimizing_coins.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dp(x + 1, INT_MAX);
    for (int i = 0; i < n; i++) {
        if (v[i] > x) continue;
        dp[v[i]] = 1;
    }
    for (int i = 0; i < x; i++) {
        if (dp[i] == INT_MAX) continue;
        for (int j = 0; j < n; j++) {
            if (i + v[j] > x) continue;
            dp[i + v[j]] = min(dp[i + v[j]], dp[i] + 1);
        }
    }
    if (dp[x] == INT_MAX) cout << -1;
    else cout << dp[x];
    cout << "\n";
}