#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe
// g++ c.cpp -o c

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<ll> pre(n), suf(n);
        pre[0] = a[0];
        suf[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], 0ll) + a[i];
            suf[n - i - 1] = max(suf[n - i], 0ll) + a[n - i - 1];
        }
        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) {
                b[i] = 0;
            }
        }
        ll ans = -1e18;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pre[i] + suf[i] - a[i] + b[i]);
        }
        cout << ans << "\n";
    }
}