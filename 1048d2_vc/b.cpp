#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll ans = 0, seconds = 1;
        if (m > n) {
            seconds = (m - n + 1);
            ans += v[0] * seconds;
            m = n - 1;
            for (int i = 1; i < n; i++) {
                ans += v[i] * (seconds + i);
            }
        }
        else {
            for (int i = n - m; i < n; i++) {
                ans += v[i] * seconds;
                seconds++;
            }
        }
        cout << ans << "\n";
    }
}
// 12:00

// 8 10