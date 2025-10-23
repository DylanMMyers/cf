#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

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
    // use state, we're looking for unique sets, so combining sets doesnt add anything to our overall score?
    vector<int> dp(x + 1 + v.back(), 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - v[i] < 0) continue;
            dp[j] = (dp[j] + dp[j - v[i]]) % MOD;
        }
    }
    cout << dp[x] << "\n";
}