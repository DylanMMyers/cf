#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< m; j++) {
            cin >> v[i][j];
        }
    }

    function<void(int, int)> dfs = [&](int i, int j) {
        v[i][j] = '#';
        if (i + 1 < n && v[i + 1][j] == '.') dfs(i + 1, j);
        if (i - 1 >= 0 && v[i - 1][j] == '.') dfs(i - 1, j);
        if (j + 1 < m && v[i][j + 1] == '.') dfs(i, j + 1);
        if (j - 1 >= 0 && v[i][j - 1] == '.') dfs(i, j - 1);
    };

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms;
}