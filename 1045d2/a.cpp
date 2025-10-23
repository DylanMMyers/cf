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
        int n, a, b; cin >> n >> a >> b;
        if (a <= b) {
            if (((n - b) % 2) == 0) cout << "YES\n";
            else cout << "NO\n";
        }
        else if (a > b) {
            if (((n - a) % 2) == 0 && ((a - b) % 2) == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}