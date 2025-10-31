#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe
// g++ d.cpp -o d

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<int> dp(n + 1, 0), dpcounts(n + 1, 0), counts(n + 1, 0);
        // how to define dp[i]
        for (int i = 1; i <= n; i++) {
            int curr = v[i - 1], prev = v[i - 1] - 1;
            counts[curr]++;
            dp[i] -= min(counts[curr], dpcounts[prev]);
            if (counts[curr] > dpcounts[prev]) {
                dp[i] += dpcounts[prev];
                dpcounts[curr] = dpcounts[prev];
            }
            else {
                dp[i] = counts[curr];
                dpcounts[curr] = dp[i];
            }
        }
        cout << dp[n] << "\n";
    }
}