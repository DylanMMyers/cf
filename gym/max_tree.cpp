#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\max_tree.exe

void dfs(int node, vector<vector<int>>& al, stack<int>& s, vector<int>& vis) {
    vis[node] = 1;
    for (int i = 0; i < al[node].size(); i++) {
        if (vis[al[node][i]]) continue;
        dfs(al[node][i], al, s, vis);
    }
    s.push(node);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> al(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            u--;
            v--;
            if (x > y) al[u].push_back(v);
            else al[v].push_back(u);
        }
        stack<int> s;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            dfs(i, al, s, vis);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[s.top()] = n - i;
            s.pop();
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
    }
}