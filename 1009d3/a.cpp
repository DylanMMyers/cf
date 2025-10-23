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
        int a, b, c ,d;
        cin >> a >> b >> c >> d;
        if (a == b && b == c && c == d) cout << "YES\n";
        else cout << "NO\n";
    }
}