#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\hungry_games2.exe

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    partial_sum(v.begin() + 1, v.end(), v.begin() + 1); // ps constructor
    vector<int> dp(n + 2);
    for (int i = n - 1; i >= 0; i--) {
        int q = upper_bound(v.begin(), v.end(), v[i] + x) - v.begin();
        dp[i] = dp[q] + q - i - 1;
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}