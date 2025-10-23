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
        int a, b, c, d; cin >> a >> b >> c >> d;
        c -= a;
        d -= b;
        if (max(a, b) - (min(a, b) * 2) > 2) cout << "NO\n";
        else if (max(c, d) - (min(c, d) * 2) > 2) cout << "NO\n";
        else cout << "YES\n";
    }
}