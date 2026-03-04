#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, long long>>> al(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        long long c; cin >> c;
        a--;
        b--;
        al[a].push_back(make_pair(b, c));
    }

    vector<long long> dist(n, 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minq;
    dist[0] = 0;
    minq.push(make_pair(0, 0));
    while (!minq.empty()) {
        int node = minq.top().second;
        long long d = dist[node];
        if (minq.top().first > d) {
            minq.pop();        
            continue;
        }
        minq.pop();        
        for (int i = 0; i < al[node].size(); i++) {
            int next_node = al[node][i].first;
            long long dist_next = al[node][i].second;
            if (d + dist_next < dist[next_node]) {
                dist[next_node] = d + dist_next;
                minq.push(make_pair(dist[next_node], next_node));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
}