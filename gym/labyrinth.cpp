#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\labyrinth.exe

bool visited[1000][1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<vector<char>> steps(n, vector<char>(m));
        pair<int, int> start, dest;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 'B') dest = {i, j}; // track where we start (to backtrack)
                if (v[i][j] == 'A') start = {i, j}; // track where we should end up
            }
        }
        bool flag = false; // have we found B from A
        pair<int,int> c; // curr node
        queue<pair<int,int>> q;
        q.push(start); // start on A
        steps[start.first][start.second] = 'X'; // mark it, we don't want to backtrack to A and keep going
        while (!q.empty()) { // q will empty or we will find B
            c = q.front();
            q.pop();

            if (v[c.first][c.second] == 'B') { // by nature of bfs, the first time we find B is guaranteed to be the shortest route
                flag = true;
                break;
            }

            visited[c.first][c.second] = true;

            if (c.first - 1 >= 0&& v[c.first - 1][c.second] != '#' && visited[c.first - 1][c.second] == false) {
                visited[c.first - 1][c.second] = 'V';
                q.push({c.first - 1, c.second});
                steps[c.first - 1][c.second] = 'U'; // mark the node we are travelling to with the direction we took to reach it
            }
            if (c.first + 1 < n && v[c.first + 1][c.second] != '#' && visited[c.first + 1][c.second] == false) {
                visited[c.first + 1][c.second] = 'V';
                q.push({c.first + 1, c.second});
                steps[c.first + 1][c.second] = 'D';
            }
            if (c.second - 1 >= 0 && v[c.first][c.second - 1] != '#' && visited[c.first][c.second - 1] == false) {
                visited[c.first][c.second - 1] = 'V';
                q.push({c.first, c.second - 1});
                steps[c.first][c.second - 1] = 'L';
            }
            if (c.second + 1 < m && v[c.first][c.second + 1] != '#' && visited[c.first][c.second + 1] == false) {
                visited[c.first][c.second + 1] = true;
                q.push({c.first, c.second + 1});
                steps[c.first][c.second + 1] = 'R';
            }
        }

        if (flag) { // if we found B
            c = {dest.first, dest.second};
            stack<char> ans;
            while (steps[c.first][c.second] != 'X') { // backtrack from B to A
                ans.push(steps[c.first][c.second]); // push each direction to the stack, then we will end up where our first step is on top of stack, ... , last move is bottom of stack
                if (ans.top() == 'U') c = {c.first + 1, c.second};
                else if (ans.top() == 'D') c = {c.first - 1, c.second};
                else if (ans.top() == 'L') c = {c.first, c.second + 1};
                else if (ans.top() == 'R') c = {c.first, c.second - 1};
            }
            cout << "YES\n" << ans.size() << "\n"; // output len of route
            while (!ans.empty()) {
                cout << ans.top(); // output step i
                ans.pop();
            }
        }
        else cout << "NO\n";
    }
}


// marking where you visit efficiently is key
// DO IT PREMEPTIVELY OR PAY THE TLE