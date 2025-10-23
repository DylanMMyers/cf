#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\building_teams.exe

bool dfs(vector<int>& a, int parent, int node, vector<vector<int>>& al) {
    if (a[node]) {
        if (a[parent] == 2 && a[node] == 2) return false;
        if (a[parent] == 1 && a[node] == 1) return false;
        return true;
    }
    
    if (parent == -1) a[node] = 1;
    else if (a[parent] == 1) a[node] = 2;
    else a[node] = 1;
    
    bool ans = true;
    for (int i = 0; i < al[node].size(); i++) {
        if (al[node][i] == parent) continue;
        ans = dfs(a, node, al[node][i], al);
        if (!ans) break;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> al(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        al[x].push_back(y);
        al[y].push_back(x);
    }
    vector<int> a(n, 0);
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (a[i]) continue;
        ans = dfs(a, -1, i, al);
        if (!ans) break;
    }
    if (ans) for (int i = 0; i < n; i++) cout << a[i] << ' ';
    else cout << "IMPOSSIBLE";
}