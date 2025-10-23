#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        ll carry = 0;
        for (int i = 0; i < n; i++) {
            carry += max(0ll, b[i] - a[i]);
            a[i] = max(a[i], b[i]);
        }
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (b[i] - (run - )
        }
        cout << ans ? "YES\n" : "NO\n";
    }
}