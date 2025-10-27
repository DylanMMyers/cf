#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./b2.exe
// g++ b2.cpp -o b2
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c, n; cin >> r >> c >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }
    queue<vector<int>> q;
    vector<vector<int>> a(r, vector<int>(c, -1)), b(r, vector<int>(c, -1));
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX)); // 0 t1, 1 t2
    for (int i = 0; i < n; i++) {
        a[v[i].first][v[i].second] = i;
        q.push({v[i].first, v[i].second, i, 0});
    }
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        int i = q.front()[0], j = q.front()[1], t = q.front()[2], d = q.front()[3];
        q.pop();
        for (int k = 0; k < 4; k++) {
            int dx = i + dir[k][0], dy = j + dir[k][1];
            if (dx < 0 || dx >= r || dy < 0 || dy >= c) continue;
            if (a[dx][dy] == -1) {
                // set tower 1 case
                a[dx][dy] = t;
                q.push({dx, dy, t, d + 1});
            }
            else if (d < dist[dx][dy] && a[dx][dy] != t) {
                // set tower 2 case
                b[dx][dy] = t;
                dist[dx][dy] = d;
                q.push({dx, dy, t, d + 1});
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] + 1 << " \n"[j == c - 1];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << b[i][j] + 1 << " \n"[j == c - 1];
        }
    }
}