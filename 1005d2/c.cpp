#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<ll> pre(n), suf(n);
        if (v[0] >= 0) pre[0] = v[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (v[i] > 0 ? v[i] : 0);
        }
        if (v.back() < 0) suf.back() = -1 * v.back();
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + (v[i] < 0 ? -1 * v[i] : 0);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pre[i] + suf[i]);
        }
        cout << ans << "\n";
    }
}