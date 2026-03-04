#include <bits/stdc++.h>
using namespace std;

// helper impl:
// can see that this one is slightly more bloated and has some extra logic which we don't need in lambda
void dfs_helper(int i, int j, int li, int lj, vector<vector<char>>& rooms) {
    // assume we are always at a '.' when this is called
    rooms[i][j] = '#';
    int n = rooms.size(), m = rooms[0].size();
    if (i + 1 < n && rooms[i + 1][j] == '.' && i + 1 != li) dfs_helper(i + 1, j, i, j, rooms);
    if (i - 1 >= 0 && rooms[i - 1][j] == '.' && i - 1 != li) dfs_helper(i - 1, j, i, j, rooms);
    if (j + 1 < m && rooms[i][j + 1] == '.' && j + 1 != lj) dfs_helper(i, j + 1, i, j, rooms);
    if (j - 1 >= 0 && rooms[i][j - 1] == '.' && j - 1 != lj) dfs_helper(i, j - 1, i, j, rooms);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> rooms(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rooms[i][j];
        }
    }
    
    // lambda impl:
    // lambda is often much more convenient to use imo so wanted to include an example of one
    // in order to call a lambda recursively, need to specify type (hence weird function thing)
    function<void(int,int,int,int)> dfs_lambda = [&](int i, int j, int li, int lj) {
        // assume we are always at a '.' when this is called
        rooms[i][j] = '#';
        if (i + 1 < n && rooms[i + 1][j] == '.' && i + 1 != li) dfs_lambda(i + 1, j, i, j);
        if (i - 1 >= 0 && rooms[i - 1][j] == '.' && i - 1 != li) dfs_lambda(i - 1, j, i, j);
        if (j + 1 < m && rooms[i][j + 1] == '.' && j + 1 != lj) dfs_lambda(i, j + 1, i, j);
        if (j - 1 >= 0 && rooms[i][j - 1] == '.' && j - 1 != lj) dfs_lambda(i, j - 1, i, j);
    };

    int room_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rooms[i][j] == '.') {
                // both work, feel free to play around
                dfs_lambda(i, j, -1, -1);
                // dfs_helper(i, j, -1, -1);
                room_count++;
            }
        }
    }
    cout << room_count;
}