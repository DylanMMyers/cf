#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> al(n); // adjacency list of graph
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        // convert 1-index to 0-index
        a--;
        b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    queue<int> q;
    vector<int> dist(n, 1e9);   // use 1e9 as "infinity", we have not reached this node yet if dist[i] = 1e9
    dist[0] = 0; // our starting node
    q.push(0); // begin bfs

    while(!q.empty()) {
        // assume if we are at a node, this is the shortest path to the node (property of bfs)
        // this means we don't need a check for outdated dist etc and can directly reference dist
        int node = q.front();
        q.pop();
        for (int i = 0; i < al[node].size(); i++) {
            int next_node = al[node][i];
            if (dist[node] + 1 < dist[next_node]) {
                dist[next_node] = dist[node] + 1;
                q.push(next_node);
            }
        }
    }

    if (dist[n - 1] == 1e9) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << dist[n - 1] + 1 << '\n';
    // now, we need to do some additional work to trace the path
    vector<int> path;
    int curr_node = n - 1;
    path.push_back(curr_node);
    while (curr_node != 0) {
        for (int i = 0; i < al[curr_node].size(); i++) {
            int prev_node = al[curr_node][i];
            if (dist[prev_node] + 1 == dist[curr_node]) {
                curr_node = prev_node;
                break;
            }
        }
        path.push_back(curr_node);
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] + 1 << ' ';
    }
}