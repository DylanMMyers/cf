#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\nenes_magical_matrix.exe

void solve() {
    int n;
    cin >> n;
    vector< vector<int> > v(n, vector<int> (n, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            v[i][j] = j + 1;
        }
        for (int j = 0; j < n; j++) {
            v[j][i] = j + 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += v[i][j];
        }
    }
    cout << ans << ' ' << 2 * n << "\n";
    for (int i = n; i > 0; i--) {
        cout << 2 << ' ' << i;
        for (int j = 1; j <= n; j++) {
            cout << ' ' << j;
        }
        cout << "\n";
        cout << 1 << ' ' << i;
        for (int j = 1; j <= n; j++) {
            cout << ' ' << j;
        }
        cout << "\n";
    }
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