#include <bits/stdc++.h>
#define ll long long
using namespace std;
// g++ conquest.cpp -o conquest
// Get-Content t.txt | .\conquest.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> al(n);
    vector<int> score(n);
    ll tot = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> score[i];
        tot += score[i];
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(n, 0);
    vis[0] = 1;
    int ans = score[0];
    for (int i = 0; i < al[0].size(); i++) {
        int node = al[0][i];
        vis[node] = 1;
        pq.push({score[node], node});
    }
    while (!pq.empty()) {
        if (ans > 1000) {
            cout << tot;
            return 0;
        }
        int scor = pq.top().first, idx = pq.top().second;
        pq.pop();
        if (ans <= scor) break;
        ans += scor;
        vis[idx] = 1;
        for (int i = 0; i < al[idx].size(); i++) {
            int node = al[idx][i];
            if (vis[node]) continue;
            vis[node] = 1;
            pq.push({score[node], node});
        }
    }
    cout << ans;
}