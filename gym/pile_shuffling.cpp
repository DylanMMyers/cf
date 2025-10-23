#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\pile_shuffling.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n; cin >> n;
        ll a, b, c, d, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c >> d;
            if (b > d) ans += a + (b - d);
            else if (a > c) ans += a - c;
        }
        cout << ans << "\n";
    }
}