#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe
// g++ d.cpp -o d

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> w(n), h(n), b(n);
    int total_weight = 0;
    ll base = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i] >> b[i];
        total_weight += w[i];
        base += b[i];
    }
    int max_head = total_weight / 2;
    vector<ll> dp(max_head + 1, -500 * 1e9 - 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        ll dif = h[i] - b[i];
        for (int j = max_head; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + dif);
        }
    }
    ll ans = -500 * 1e9 - 1;
    for (int i = 0; i <= max_head; i++) {
        ans = max(ans, dp[i]);
    }
    cout << base + ans;
}