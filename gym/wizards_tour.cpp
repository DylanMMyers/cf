#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe
// g++ file.cpp -o file

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> al(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    vector<vector<int>> dt(n);
    vector<int> vis(n, 0);
    function<void(int)> dfs = [&] (int u) {
        for (int v : al[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dt[u].push_back(v);
                dfs(v);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i);
            comps.push_back(i);
        }
    }
    cout << '';
}