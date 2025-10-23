#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if ((n - i + 1) - i > 0) ans += (n - i + 1) - i;
            else ans -= (n - i + 1) - i;
        }
        cout << 1 + (ans / 2) << "\n";
    }
}