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
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            v[i].resize(x);
            for (int j = 0; j < x; j++) {
                cin >> v[i][j];
            }
        }
        vector<int> c(m + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                c[v[i][j]]++;
            }
        }
        int r = 0;
        for (int i = 0; i < n; i++) {
            bool can = true;
            for (int j = 0; j < v[i].size(); j++) {
                if (c[v[i][j]] <= 1) can = false;
            }
            if (!can) continue;
            r++;
        }
        for (int i = 1; i <= m; i++) {
            if (c[i] < 1) {
                r = 0;
                break;
            }
        }
        cout << (r >= 2 ? "YES\n" : "NO\n");
    }
}