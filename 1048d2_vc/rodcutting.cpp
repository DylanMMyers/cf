#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\rodcutting.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> price(n + 1); for (int i = 1; i <= n; i++) cin >> price[i];
    vector<int> dp(n + 1, 0);
    dp[1] = price[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = price[i];
        for (int j = i - 1; j > 0; j--) {
            dp[i] = max(dp[i], dp[i - j] + dp[j]);
        }
    }
    cout << dp[n];
}