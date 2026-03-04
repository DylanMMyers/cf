#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> al(n); // adjacency list of graph
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        // 1-index to 0-index
        a--;
        b--;
        al[a].push_back(b);
    }

    bool cycle = false;
    // vis[i] has 3 states:
    // 0: node is completely unvisited
    // 1: node is visited in CURRENT dfs iter, meaning if we can/need to visit this node again we have a cycle
    // 2: node is completely visited in some previous dfs iter
    // topo holds the topological ordering of the graph (in reverse, stack also works here)
    vector<int> vis(n), topo;
    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for (int i = 0; i < al[node].size(); i++) {
            int next_node = al[node][i];
            if (vis[next_node] == 0) dfs(next_node);
            else if (vis[next_node] == 1) {
                cycle = true;
                return;
            }
        }

        vis[node] = 2;
        topo.push_back(node);
    };

    // now, try to visit all unvisited nodes
    // if we run into impossible case (cycle), we can just disregard and report on the spot
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) dfs(i);
        if (cycle) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << topo[i] + 1 << ' ';
    }
}