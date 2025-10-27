#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./d.exe
// g++ d.cpp -o d
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c; cin >> r >> c;
    int cx, cy; cin >> cx >> cy;
    cx--;
    cy--;
    int ex, ey; cin >> ex >> ey;
    ex--;
    ey--;
    vector<string> v(r);
    for (int i = 0; i < r; i++) {
        cin >> v[i];
    }
    vector<vector<vector<int>>> vis(r, vector<vector<int>>(c, vector<int>(4, 0)));
    int currdir = 0;
    vector<vector<int>> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; // R U L D
    vector<vector<int>> brute = {{1, 0, 3, 2}, {2, 1, 0, 3}, {3, 2, 1, 0}, {0, 3, 2, 1}};
    bool ok = false;
    while (currdir != -1) {
        if (cx == ex && cy == ey) {
            ok = true;
            break;
        }
        int nextdir = -1;
        for (int i = 0; i < 4; i++) {
            int dx = dir[brute[currdir][i]][0], dy = dir[brute[currdir][i]][1];
            if (cx + dx < 0 || cx + dx >= r) continue;
            if (cy + dy < 0 || cy + dy >= c) continue;
            if (v[cx + dx][cy + dy] == '0') {
                if (vis[cx][cy][brute[currdir][i]] == 0) {
                    nextdir = brute[currdir][i];
                    vis[cx][cy][brute[currdir][i]] = 1;
                    cx += dx;
                    cy += dy;
                }
                break;
            }
        }
        currdir = nextdir;
    }
    cout << (ok ? 1 : 0);
}