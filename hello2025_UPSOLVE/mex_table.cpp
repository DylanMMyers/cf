#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\mex_table.exe

void solve() {
    int n, m;
    cin >> n >> m;
    // 0 1 2 3 4
    // 5 6 7 8 9
    // 10 11 12 13 14 

    // sum of mex of row/col with 0 in it, best way to do it is 1 + length of longest row/col
    if (n > m) cout << 1 + n << "\n";
    else cout << 1 + m << "\n";
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