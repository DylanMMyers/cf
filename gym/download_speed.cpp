#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\download_speed.exe
// g++ download_speed.cpp -o download_speed

int n;
vector<vector<ll>> capacity;
vector<vector<ll>> adj;

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, 1e18});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t) {
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int m; cin >> m;
    capacity.assign(n, vector<ll>(n, 0));
    adj.resize(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, c; cin >> u >> v >> c;
        u--;
        v--;
        if (!capacity[u][v] && !capacity[v][u]) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        capacity[u][v] += c;
    }
    cout << maxflow(0, n - 1);
}