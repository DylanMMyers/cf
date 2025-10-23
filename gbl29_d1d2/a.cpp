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
        int x, y; cin >> x >> y;
        if (y > x) cout << "2\n";
        else if (y == 1) cout << "-1\n"; 
        else if (x - 1 > y) cout << "3\n";
        else cout << "-1\n";
    }
}