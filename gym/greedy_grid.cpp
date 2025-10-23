#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\greedy_grid.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        if ((n <= 2 && m <= 2) || n == 1 || m == 1) cout << "NO\n";
        else cout << "YES\n"; 
    }
}