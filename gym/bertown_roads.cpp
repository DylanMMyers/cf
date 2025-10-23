#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\bertown_roads.exe

// construct dfs tree
// use tarjans algorithm to determine if a bridge exists:
// if the earliest node that a child can reach is later than the current node, a bridge exists
// if bridge, output 0
// otherwise we output res, constructed during the dfs:
// if we reach an already visited node which was discovered earlier than the current node, this is a back edge
// otherwise it is a normal child of the node in the dfs tree
// regardless, we should go from the current node to both of these (push directed edge to res)
// this arrangement works because to "transcend" the levels of the tree, we must be able to use some back edge to go to an earlier node
// it doesnt really matter how you arrange the tree, its easy to think about at the leaves of the tree why this works

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
    vector<pair<int,int>> res;
    vector<int> low(n, -1), disc(n, -1), vis(n, 0);
    int timer = 0;
    bool bridge = false;
    function<void(int, int)> dfs = [&](int u, int parent) {
        vis[u] = 1;
        disc[u] = low[u] = timer++;
        for (int i = 0; i < al[u].size(); i++) {
            int v = al[u][i];
            if (v == parent) continue;
            if (vis[v]) {
                low[u] = min(low[u], disc[v]);
                if (disc[u] > disc[v]) res.push_back({u, v});
            }
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) bridge = true;
                res.push_back({u, v});
            }
        }
    };
    dfs(0, -1);
    // need to check every node in dfs tree of 0
    // if both nodes do not contain a back edge (node to previous element <not in subtree?>)
    if (bridge) {
        cout << '0';
        return 0;
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first + 1 << ' ' << res[i].second + 1 << "\n";
    }
}