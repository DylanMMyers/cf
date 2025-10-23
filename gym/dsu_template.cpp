#include <bits/stdc++.h>

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
};