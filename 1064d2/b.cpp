#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll a, b, n; cin >> a >> b >> n;
        ll ans;
        if (a/n < b) {
            if (n == 1) ans = 1;
            else if (a <= b) ans = 1;
            else ans = 2;
        }
        else ans = 1;
        cout << ans << "\n";
    }
}