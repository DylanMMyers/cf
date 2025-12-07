#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe
// g++ c.cpp -o c

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            cin >> v[0][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> v[1][i];
        }
        vector<vector<pair<int,int>>> bounds(n, vector<pair<int,int>>(n, {1, n}));
        bounds[0][0] = {v[0][0], v[0][0]};
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                bounds[0][i + 1] = {min(v[0][i + 1], bounds[0][i].first), max(v[0][i + 1], bounds[0][i].second)};
            }
            bounds[1][i] = {min(v[1][i], bounds[0][i].first), max(v[1][i], bounds[0][i].second)};
        }
        set<int> l, r;
        for (int i = 1; i <= max(bounds[0][n - 1].first, bounds[1][n - 2].first); i++) {
            l.insert(i);
        }
        for (int i = max(bounds[0][n - 1].second, bounds[1][n - 2].second); i <= 2 * n; i++) {
            r.insert(i);
        }
        cout << l.size() * r.size() << "\n";
    }
}