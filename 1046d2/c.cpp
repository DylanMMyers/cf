#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        vector<int> dp(n + 1, 0);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) mp[v[i]].push_back(i);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            int idx = lower_bound(mp[v[i]].begin(), mp[v[i]].end(), i) - mp[v[i]].begin();
            if (idx + v[i] - 1 < mp[v[i]].size()) {
                dp[i] = max(dp[i], v[i] + dp[mp[v[i]][idx + v[i] - 1] + 1]);
            }
        }
        cout << dp[0] << "\n";
    }
}