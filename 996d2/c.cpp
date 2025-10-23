#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

void solve() {
    // start along the beginning of the path and find the sum of of the first direction and column, this gives us a "concrete" start
    // then we iterate to the end, noting the variables and free variables or their relaionship to previous variables respectively if we cannot currently compute an answer
    // once we reach the end, we have some finite answers and we can backtrack down the path and use our new values and established variable relationships to determine an answer for a_ij
    // no chance in hell this is getting implemented in 10 mins

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector< vector<int> > v(n, (vector<int> (m)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    // we can iterate through to the final value and establish some relationships, then backtrack
    int row = 0, col = 0, crow = 0, ccol = 0; // row and col are it, crow and ccol tracks curr sum
    for (int i = 0; i < n + m - 2; i++) {
        crow = 0, ccol = 0;
        for (int j = 0; j < n; j++) {
            ccol += v[j][col];
        }
        for (int j = 0; j < m; j++) {
            crow += v[row][j];
        }

        if (s[i] == 'D') { // we are doing algebra with curr and down
            if (crow > ccol) v[row + 1][col] = crow - ccol;
            else v[row + 1][col] = ccol - crow;
            row++;
        }
        else { // we are doing algebra with curr and right
            if (crow > ccol) v[row][col + 1] = crow - ccol;
            else v[row][col + 1] = ccol - crow;
            col++;
        }
    }

    int x = 0; // our x is guaranteed at this point, so it will be equal to the final value unless its a free variable
    if (s[n + m - 3] == 'R') {
        for (int i = 0; i < n; i++) {
            x += v[i][m - 1];
        }
    }
    else {
        for (int i = 0; i < m; i++) {
            x += v[n - 1][i];
        }
    }

    row = n - 1, col = m - 1;
    for (int i = n + m - 3; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            ccol += v[j][col];
        }
        for (int j = 0; j < m; j++) {
            crow += v[row][j];
        }

        if (s[i] == 'D') { // x = a + row
            v[row][col] = x - crow;
            row--;
        }
        else { // x = a + col
            v[row][col] = x - ccol;
            col--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << ' ';
        }
        cout << "\n";
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}