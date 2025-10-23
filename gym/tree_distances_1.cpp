#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\tree_distances_1.exe

int dfs(int node, int parent, int d, vector<int>& dist, vector<vector<int>>& al) {
    dist[node] = max(dist[node], d);
    for (int i = 0; i < al[node].size(); i++) {
        if (al[node][i] == parent) continue;
        dist[node] = max(dist[node], dfs(al[node][i], node, d + 1, dist, al));
    }
    return dist[node];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> al(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        vector<int> dist1(n, 0), dist2(n, 0);
        dfs(0, -1, 0, dist1, al);
        int tw = 0;
        for (int i = 0; i < n; i++) {
            if (dist1[i] > dist1[tw]) tw = i;
        }
        dfs(tw, -1, 0, dist2, al);
        for (int i = 0; i < n; i++) cout << max(dist1[i], dist2[i]) << " \n"[i == n - 1];
    }
}