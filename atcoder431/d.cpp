#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe
// g++ d.cpp -o d

// WIP

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> w(n), h(n), b(n);
    int total_weight = 0;
    ll happiness = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i] >> b[i];
        total_weight += w[i];
        happiness += b[i];
    }
    vector<vector<ll>> dp(total_weight + 1, vector<ll>(2, 0));
    dp[0][1] = happiness;
    for (int i = 1; i <= total_weight; i++) {
        for (int j = 0; j < n; j++) {
            if (h[j] <= b[j]) continue;
            // doesnt work because reusing multiple, needs to be 01
            // probably should go by item first, then weight to avoid this
            if (i - w[j] >= 0 && dp[i - w[j]][0] + h[j] > dp[i][0]) {
                dp[i][0] = dp[i - w[j]][0] + h[j];
                dp[i][1] = dp[i - w[j]][1] - b[j];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= total_weight / 2 + (total_weight % 2); i++) {
        ans = max(ans, dp[i][0] + dp[i][1]);
    }
    cout << ans;
}