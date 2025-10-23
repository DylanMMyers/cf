#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\coin_combinations_1.exe

int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> dp(x + 1 + v.back(), 0);
    dp[0] = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i]) dp[i + v[j]] = (dp[i + v[j]] + dp[i]) % MOD;
        }
    }
    cout << dp[x] << "\n";
}