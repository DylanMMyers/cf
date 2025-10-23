#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

// just use dijkstra so go from each tile to next tile where count of jumps + 1 less than count of nexxt tiles jumps
// vloge (n*m*log(n*m))

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j] - '0';
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        int i = pq.top()[1], j = pq.top()[2], curr = pq.top()[0];
        int jump = v[i][j];
        pq.pop();
        if (i + jump < n && dist[i][j] + 1 < dist[i + jump][j]) {
            dist[i + jump][j] = dist[i][j] + 1;
            pq.push({dist[i + jump][j], i + jump, j});
        }
        if (i - jump >= 0 && dist[i][j] + 1 < dist[i - jump][j]) {
            dist[i - jump][j] = dist[i][j] + 1;
            pq.push({dist[i - jump][j], i - jump, j});
        }
        if (j + jump < m && dist[i][j] + 1 < dist[i][j + jump]) {
            dist[i][j + jump] = dist[i][j] + 1;
            pq.push({dist[i][j + jump], i, j + jump});
        }
        if (j - jump >= 0 && dist[i][j] + 1 < dist[i][j - jump]) {
            dist[i][j - jump] = dist[i][j] + 1;
            pq.push({dist[i][j - jump], i, j - jump});
        }
    }
    cout << (dist[n - 1][m - 1] == INT_MAX ? -1 : dist[n - 1][m - 1]);
}