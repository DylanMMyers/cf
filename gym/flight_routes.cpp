#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\flight_routes.exe

// sol: use scc data structure to find all scc
// if there is only one scc, answer is always yes
// if there is multiple scc, answer is no
// we can select any 2 elements from either scc, then check whether we are able to visit one from the other
// it is guaranteed that one will not be reachable from the other, so figure out which a cannot reach a b and output them 

struct SCC {
    public:
    int n, scc_count;
    vector<vector<int>> adj, radj, dag, members;
    vector<int> comp, order, indeg, outdeg;
    vector<bool> vis;

    SCC(int n_) : n(n_), adj(n), radj(n), comp(n, -1), vis(n, false) {}

    void add(int u, int v) {
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    void dfs1(int v) {
        vis[v] = true;
        for (int w : adj[v]) if (!vis[w]) dfs1(w);
        order.push_back(v);
    }

    void dfs2(int v, int id) {
        comp[v] = id;
        members[id].push_back(v);
        for (int w : radj[v]) if (comp[w] == -1) dfs2(w, id);
    }

    void build() {
        fill(vis.begin(), vis.end(), false);
        order.clear();
        for (int v = 0; v < n; ++v) if (!vis[v]) dfs1(v);
        comp.assign(n, -1);
        scc_count = 0;
        members.clear();
        members.resize(n);
        for (int i = n-1; i >= 0; --i) {
            int v = order[i];
            if (comp[v] == -1) {
                members[scc_count].clear();
                dfs2(v, scc_count++);
            }
        }
        members.resize(scc_count);
        dag.assign(scc_count, {});
        indeg.assign(scc_count, 0);
        outdeg.assign(scc_count, 0);
        for (int v = 0; v < n; ++v) {
            for (int w : adj[v]) {
                int cv = comp[v], cw = comp[w];
                if (cv != cw) {
                    dag[cv].push_back(cw);
                }
            }
        }
        for (int i = 0; i < scc_count; ++i) {
            sort(dag[i].begin(), dag[i].end());
            dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
            for (int j : dag[i]) {
                indeg[j]++;
                outdeg[i]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    SCC scc = SCC(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        scc.add(u, v);
    }
    scc.build();
    if (scc.members.size() == 1) cout << "YES\n";
    else {
        int node1 = 0, node2 = -1;
        for (int i = 1; i < n; i++) {
            if (scc.comp[i] != scc.comp[node1]) {
                node2 = i;
                break;
            }
        }
        vector<int> vis(n, 0);
        function<void(int)> dfs = [&](int node) {
            if (vis[node]) return;
            vis[node] = 1;
            for (int i = 0; i < scc.adj[node].size(); i++) {
                dfs(scc.adj[node][i]);
            }
        };
        dfs(node1);
        if (vis[node2]) swap(node1, node2);
        cout << "NO\n";        
        cout << node1 + 1 << ' ' << node2 + 1;
    }
}