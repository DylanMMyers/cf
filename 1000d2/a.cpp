#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

void solve() {
    int l, r;
    cin >> l >> r;
    if (l == 1 && r == 1) cout << "1\n";
    else cout << r - l << "\n";
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