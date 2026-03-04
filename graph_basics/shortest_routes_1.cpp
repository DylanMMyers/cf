#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, long long>>> al(n); // adjacency list
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        long long c; cin >> c;
        a--; // convert 1-index to 0-index
        b--;
        al[a].push_back(make_pair(b, c));
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minq; // min priority queue
    vector<long long> dist(n, 1e18); // pick large number as "infinity"
    dist[0] = 0; // distance to starting node is 0
    minq.push(make_pair(0, 0)); // start from first city (0-indexed)
    
    while (!minq.empty()) {
        int sc = minq.top().second; // starting city
        long long d = minq.top().first; // current shortest length travel to start_city
        minq.pop();
        if (d > dist[sc]) continue;
        for (int i = 0; i < al[sc].size(); i++) {
            int dc = al[sc][i].first; // destination city
            long long dc_c = al[sc][i].second; // length of travel from sc to dc
            if (d + dc_c < dist[dc]) {
                dist[dc] = d + dc_c;
                minq.push(make_pair(dist[dc], dc));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
}