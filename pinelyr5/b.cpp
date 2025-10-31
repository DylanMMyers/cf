#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        // all disconnected black cells MUST be reachable diagonally in some way shape or form
        // define a cross as creating a length 3 black strip
        // all disconnected nodes need to be diagonal of each other

        // lets try to connect all nodes diagonally that can be validly connected (we will search along all diagonals and try to connect to the first node we see if we see one)
        // then bfs after to see if:
        // all nodes are reached
        // no cross exists

        vector<vector<int>> diag({-1, -1}, {-1, 1}, {1, 1}, {1, -1});
        bool ok = true;
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == '.') continue;
                c++;
                for (int k = 0; k < 4; k++) {
                    int x = i + diag[k][0], y = j + diag[k][1];
                    while (x < n && x >= 0 && y < n && y >= 0) {
                        if (v[x][y] == '.') continue;
                    }
                    if (x < n && x >= 0 && y < n && y >= 0) { // found a black cell
                        // now check if its reachable
                        int vert = 0, hori = 0;
                        
                    }
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}

