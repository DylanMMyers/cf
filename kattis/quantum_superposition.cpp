#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\quantum_superposition.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n1, n2, m1, m2; cin >> n1 >> n2 >> m1 >> m2;
    vector<vector<int>> al1(n1), al2(n2), in1(n1), in2(n2);
    int u, v;
    for (int i = 0; i < m1; i++) {
        cin >> u >> v;
        u--;
        v--;
        al1[u].push_back(v);
        in1[v].push_back(u);
    }
    for (int i = 0; i < m2; i++) {
        cin >> u >> v;
        u--;
        v--;
        al2[u].push_back(v);
        in2[v].push_back(u);
    }
    vector<vector<bool>> dp1(n1, vector<bool>(m1 + 1, false)), dp2(n2, vector<bool>(m2 + 1, false));
    vector<int> vis(n1, 0), topo;
    stack<int> s;
    function<void(int)> dfs1 = [&](int u) -> void {
        if (vis[u]) return;
        vis[u] = 1;
        for (int j = 0; j < al1[u].size(); j++) {
            if (!vis[al1[u][j]]) dfs1(al1[u][j]);
        }
        s.push(u);
    };
    for (int i = 0; i < n1; i++) {
        if (vis[i]) continue;
        dfs1(i);
    }
    for (int i = 0; i < n1; i++) {
        topo.push_back(s.top());
        s.pop();
    }
    dp1[0][0] = 1;
    for (int i = 1; i < n1; i++) {
        int u = topo[i];
        for (int j = 0; j < in1[u].size(); j++) {
            int v = in1[u][j];
            for (int k = 0; k < m1; k++) {
                if (dp1[v][k]) dp1[u][k + 1] = true;
            }
        }
    }
    vis = vector<int>(n2, 0);
    topo.clear();
    function<void(int)> dfs2 = [&](int u) -> void {
        if (vis[u]) return;
        vis[u] = 1;
        for (int j = 0; j < al2[u].size(); j++) {
            if (!vis[al2[u][j]]) dfs2(al2[u][j]);
        }
        s.push(u);
    };
    for (int i = 0; i < n2; i++) {
        if (vis[i]) continue;
        dfs2(i);
    }
    for (int i = 0; i < n2; i++) {
        topo.push_back(s.top());
        s.pop();
    }
    dp2[0][0] = 1;
    for (int i = 1; i < n2; i++) {
        int u = topo[i];
        for (int j = 0; j < in2[u].size(); j++) {
            int v = in2[u][j];
            for (int k = 0; k < m2; k++) {
                if (dp2[v][k]) dp2[u][k + 1] = true;
            }
        }
    }
    vector<bool> reachable(m1 + m2 + 1, false);
    for (int i = 0; i <= m1; i++) {
        for (int j = 0; j <= m2; j++) {
            if (dp1[n1 - 1][i] && dp2[n2 - 1][j]) reachable[i + j] = true;
        }
    }
    int qq; cin >> qq;
    for (int i = 0; i < qq; i++) {
        int x; cin >> x;
        if (x > m1 + m2) cout << "No\n";
        else cout << (reachable[x] ? "Yes\n" : "No\n");
    }
}