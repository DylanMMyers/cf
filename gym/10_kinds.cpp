#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c; cin >> r >> c;
    vector<string> v(r);
    for (int i = 0; i < r; i++) {
        cin >> v[i];
    }
    vector<vector<int>> id(r, vector<int>(c, -1));
    int idptr = 0;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) id[r][c] = idptr ++;
    DSU dsu = DSU(r * c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char curr = v[i][j];
            if (i - 1 >= 0 && (v[i - 1][j] == curr)) dsu.join(dsu.find(i * c + j), dsu.find((i - 1) * c + j));
            if (i + 1 < r && (v[i + 1][j] == curr)) dsu.join(dsu.find(i * c + j), dsu.find((i + 1) * c + j));
            if (j - 1 >= 0 && (v[i][j - 1] == curr)) dsu.join(dsu.find(i * c + j), dsu.find(i * c + j - 1));
            if (j < c && (v[i][j + 1] == curr)) dsu.join(dsu.find(i * c + j), dsu.find(i * c + j + 1));
        }
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        if (dsu.find(r1 * c + c1) == dsu.find(r2 * c + c2)) cout << (v[r1][c1] == '0' ? "binary\n" : "decimal\n");
        else cout << "neither\n";
    }
}