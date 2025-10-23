#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        if (x == y) cout << "NO\n";
        else if (x % 9 == 0 && y == 1) cout << "YES\n";
        else if (x + 1 == y) cout << "YES\n";
        else if (x > y && (x - y + 1) % 9 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}