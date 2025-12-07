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
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<ll> ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + v[i - 1];
        }
        ll ans = ps[n];
        int l = 1, r = 1;
        while (r <= n) {
            ll x = (r - l) + 1;
            ll score = x * (l + r) + ps[l - 1] + (ps[n] - ps[r]);
            ans = max(score, ans);
            if (score > ps[n]) {
                r++;
            }
            else if (l < r) {
                l++;
            }
            else {
                l++;
                r++;
            }
        }
        for (int i = l; i <= n; i++) {
            ll score = ps[l - 1] + (n - i + 1) * (i + n); 
            ans = max(ans, score);
        }
        cout << ans << "\n";
    }
}