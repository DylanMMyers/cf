#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\final_countdown.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            it *= 10;
        }
        // for each pos, x_i, we will need to do it 10^k * ele, where k is its pos from the right. It will take extra seconds depending on values to the left
        // (for 25, we only need to wait 2 seconds for the 10s twice, for 125 we have to wait 2 seconds for the 10s 12 times, it increments based on prev)
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            int curr = s[i - 1] - '0' * it;
            it /= 10;
            if (!c) continue;
            dp[i] = () - dp[i]; // avoid double counting
        }
        ll ans = dp.back();
        for (int i = n - 1; i >= 0; i--) {
            ans += (s[i] - '0') * it;
            it *= 10;
        }
        cout << ans << "\n";
    }
}