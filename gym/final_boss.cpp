#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\final_boss.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        ll h, n;
        cin >> h >> n;
        vector<int> a(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        /*vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j += v[i].second) {
                dp[i] += v[i].first;
            }
        }
        for (int i = 0; i < n; i++) {
            h -= dp[i];
            if (h <= 0) {
                cout << i + 1 << "\n";
                return;
            }
        }
        cout << n << "\n";
        return;
        too slow, bs nlogn*/
        ll low = 1, high = 4e10; // locate upper bound of bs better to avoid overflow
        while (low < high) {
            ll mid = (high + low) / 2; // can do low + (high - low) / 2 to avoid overflow
            ll curr = 0;
            for (int i = 0; i < n; i++) {
                curr += a[i] * (1 + ((mid - 1) / c[i])); // think ab the case better
                if (curr >= h) break;
            }
            if (curr < h) low = mid + 1; // if our mid doesn't work, use + 1 to disclude
            else high = mid; // here we want to continue considering the mid as it may be the answer, otherwise we can use -1 to ingore it
        }

        cout << low << "\n";
    }
}