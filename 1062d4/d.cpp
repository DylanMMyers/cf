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
        ll n; cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (v[i] % 2) {
                ans = (ll)2;
                break;
            }
            for (int j = 3; j <= 99; j += 2) {
                if ((ll)gcd(v[i], (ll)j) == (ll)1) ans = min((ll)ans, (ll)j);
            }
        }
        if (ans == LLONG_MAX) ans = -1;
        cout << ans << "\n";
    }
}