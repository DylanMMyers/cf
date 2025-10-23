#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        // it only matters in subgrids that 0 exists in
        // so lets think about where we place 0 and its subgrids first
        // so then we can just place 0 in the most internal position
        // then keep counting up in "rings"
        // so for even n:
        // we will place 0 in the top left of the center "square", then surround it in rings until we place the L in the bottom right
        // then for odd:
        // we place 0 in the center and just surround it
        vector<vector<int>> v(n, vector<int> (n, -1));
        if (n % 2 == 1) {
            v[(n / 2)][(n / 2)] = 0;
            int iter = (n / 2) - 1, x, y, c = 1;
            while (iter >= 0) {
                x = (n / 2);
                y = iter;
                while (x < n - iter) {
                    v[y][x] = c;
                    x++;
                    c++;
                }
                x--;
                y++;
                while (y < n - iter) {
                    v[y][x] = c;
                    y++;
                    c++;
                }
                y--;
                x--;
                while (x > iter - 1) {
                    v[y][x] = c;
                    x--;
                    c++;
                }
                x++;
                y--;
                while (y > iter - 1) {
                    v[y][x] = c;
                    c++;
                    y--;
                }
                y++;
                x++;
                while (x < (n / 2)) {
                    v[y][x] = c;
                    c++;
                    x++;
                }
                iter--;
            }
        }
        else {
            v[(n / 2) - 1][(n / 2) - 1] = 0;
            int iter = (n / 2), x, y, c = 1, track = 1;
            while (iter < n) {
                x = iter, y = (n / 2) - 1;
                int curr = 0;
                while (curr < track) {
                    v[x][y] = c;
                    curr++;
                    y++;
                    c++;
                }
                curr = 0;
                while (curr <= track) {
                    v[x][y] = c;
                    curr++;
                    x--;
                    c++;
                }
                iter++;
                track++;
            }
            iter = (n / 2) - 2;
            while (iter >= 0) {
                x = n - 1, y = iter;
                while (v[x][y + 1] > -1) {
                    v[x][y] = c;
                    c++;
                    y--;
                }
                for (int i = y; i < n; i++) {
                    v[x][i] = c;
                    c++;
                }
                iter--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << v[i][j] << " \n"[j == n - 1];
            }
        }
    }
}