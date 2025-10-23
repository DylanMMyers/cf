#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

void solve() {
    int n;
    cin >> n;
    if (n < 5) {
        cout << -1 << "\n";
        return;
    }
    // 1 2 3 4 5 6 7
    // 1 3 5 7
    // 2 4 6 8
    // MAGIC NUMBER 9
    cout << 2;
    for (int i = 6; i <= n; i += 2) {
        if (i != 4) cout << ' ' <<  i;
    }
    cout << ' ' << 4 << ' ' << 5;
    for (int i = 1; i <= n; i += 2) {
        if (i != 5) cout << ' ' << i;
    }
    cout << "\n";
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