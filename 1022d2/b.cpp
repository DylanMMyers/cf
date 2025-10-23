#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, x;
        cin >> n >> x;
        if (n == 1) {
            if (x == 0) cout << -1 << '\n';
            else cout << x << '\n';
        } 
        else if (n == 2) {
            if (x == 0) cout << 2 << '\n';
            else if (x == 1) cout << 5 << '\n';
            else cout << x + 4 << '\n';
        } 
        else {
            cout << x + n - (n % 2) << '\n';
        }
    }
}