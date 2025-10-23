#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\deceptive_discussions.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n; cin >> m >> n;
    vector<vector<char>> v(n, vector<char>(m));
    int si, sj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }
    string s; cin >> s;
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[si][sj] = 0;
    q.push({si, sj});
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        int d = dist[i][j];
        q.pop();
        if (i + 1 < n && dist[i + 1][j] == -1 && v[i + 1][j] != '#') {
            dist[i + 1][j] = d + 1;
            q.push({i + 1, j});
        }
        if (i - 1 >= 0 && dist[i - 1][j] == -1 && v[i - 1][j] != '#') {
            dist[i - 1][j] = d + 1;
            q.push({i - 1, j});
        }
        if (j + 1 < m && dist[i][j + 1] == -1 && v[i][j + 1] != '#') {
            dist[i][j + 1] = d + 1;
            q.push({i, j + 1});
        }
        if (j - 1 >= 0 && dist[i][j - 1] == -1 && v[i][j - 1] != '#') {
            dist[i][j - 1] = d + 1;
            q.push({i, j - 1});
        }
    }
    vector<char> c = {'N', 'E', 'S', 'W'};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    q.push({si, sj});
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        int d = dist[i][j];
        q.pop();
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        if (d == s.length()) v[i][j] = '!';
        else {
            if (s[d] != c[0] && i - 1 >= 0 && dist[i - 1][j] == d + 1 && v[i - 1][j] != '#') q.push({i - 1, j});
            if (s[d] != c[2] && i + 1 < n && dist[i + 1][j] == d + 1 && v[i + 1][j] != '#') q.push({i + 1, j});
            if (s[d] != c[3] && j - 1 >= 0 && dist[i][j - 1] == d + 1 && v[i][j - 1] != '#') q.push({i, j - 1});
            if (s[d] != c[1] && j + 1 < m && dist[i][j + 1] == d + 1 && v[i][j + 1] != '#') q.push({i, j + 1});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
}