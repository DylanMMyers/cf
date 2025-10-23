#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    ll n, ans = 0, iter = 3, next = 1;
    cin >> n;
    while (next < n) {
        ans++;
        next += iter;
        iter *= 2;
    }
    ans++;
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}