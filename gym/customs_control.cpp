#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<vector<int>> al(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    pq.push({0, 0});
    while (!pq.empty()) {
        int score, index;
        index = pq.top().second;
        score = pq.top().first;
        pq.pop();
        if (dist[index] < score) continue;
        dist[index] = score;
        for (int i = 0; i < al[index].size(); i++) {
            int currnode = al[index][i];
            if (dist[index] + v[currnode] < dist[currnode]) {
                dist[currnode] = dist[index] + v[currnode];
                pq.push({dist[currnode], currnode});
            }
        }
    }
    int mincost = INT_MAX;
    for (int i = 0; i < al[n - 1].size(); i++) {
        mincost = min(mincost, dist[al[n - 1][i]]);
    }
    
}