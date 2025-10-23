#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\roads.exe

class DSU {
    public:
    vector<int> par;
    vector<int> sz;
    DSU (int n) {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<int>(n, 1);
    }
    
    int find(int u) {
        if (par[u] != u) {
            par[u] = find(par[u]);
        }
        return par[u];
    }
    
    void join(int u, int v){
        u = find(u);
        v = find(v);
        if (u != v) {
            if (sz[u] <= sz[v]) {
                sz[v] += sz[u];
                par[u] = v;
            }
            else {
                sz[u] += sz[v];
                par[v] = u;
            }
        }
    }

    int getsz(int u) {
        return sz[find(u)];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    DSU dsu = DSU(n);
    int components = n, maxsize = 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (dsu.find(u) != dsu.find(v)) {
            components--;
            dsu.join(dsu.find(u), dsu.find(v));
            maxsize = max(maxsize, dsu.getsz(dsu.find(u)));
        }
        cout << components << ' ' << maxsize << "\n";
    }
}