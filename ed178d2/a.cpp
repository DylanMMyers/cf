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
        int a, b, c;
        cin >> a >> b >> c;
        if (c > (b - a)) {
            c -= b - a;
            if ((c >= b) && (c - b) % 3 == 0) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
}