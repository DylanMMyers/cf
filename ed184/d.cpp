#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe
// g++ d.cpp -o d

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll x, y, k; cin >> x >> y >> k;
        ll lo = 1, hi = 1e12 + 1;
        bool ok = false;
        ll ans;
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            ll pos = mid;
            for (int i = 0; i < x; i++) {
                pos -= pos / y;
            }
            if (pos < k) lo = mid + 1;
            else hi = mid;
            if (pos == k) ok = true;
        }
        if (ok) cout << lo << "\n";
        else cout << "-1\n";
    }
}