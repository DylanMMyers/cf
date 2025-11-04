#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\haunted_house.exe
// g++ haunted_house.cpp -o haunted_house

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int,int>> v(n);
    vector<vector<pair<int,int>>> al(n, vector<pair<int,int>>(n, {0, -1}));
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    int nscore = v[n - 1].first;
    for (int i = 0; i < m; i++) {
        int u, vv, t; cin >> u >> vv >> t;
        u--;
        vv--;
        al[u][vv] = al[vv][u] = {1, t};
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        in[v[i].second] = 1;
        if (!in[n - 1]) continue;
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty()) {
            int node = pq.top().second; // B
            int currdist = dist[node]; // 2
            pq.pop();
            for (int j = 0; j < n; j++) {
                if (al[node][j].first == 0 || node == j || !in[j]) continue;
                int t = al[node][j].second;
                if (dist[j] > currdist + t) {
                    dist[j] = currdist + t;
                    pq.push({dist[j], j});
                }
            }
        }
        if (dist[n - 1] <= k) {
            cout << v[i].first;
            return 0;
        }
    }
    cout << "TRAPPED";
}