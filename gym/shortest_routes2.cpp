#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\shortest_routes2.exe
// g++ shortest_routes2.cpp -o shortest_routes2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> d(n, vector<ll>(n, 1e18));
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        ll u, v, x; cin >> u >> v >> x;
        u--;
        v--;
        d[u][v] = d[v][u] = min(d[u][v], x);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] < 1e18 && d[k][j] < 1e18) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        if (d[u][v] < 1e18) cout << d[u][v];
        else cout << -1;
        cout << "\n";
    }
}