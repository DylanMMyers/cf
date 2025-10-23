#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c_UPSOLVE.exe

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<ll>> v(n, vector<ll> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    ll row = 0, col = 0, curr = 0; // row and col are iter, curr tracks sum of row or col depending on operation
    for (int i = 0; i < n + m - 1; i++) {
        curr = 0;
        if (s[i] == 'R') {
            for (int j = 0; j < n; j++) {
                curr += v[j][col];
            }
            v[row][col] -= curr;
            col++;
        }
        else {
            for (int j = 0; j < m; j++) {
                curr += v[row][j];
            }
            v[row][col] -= curr;
            row++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i][0];
        for (int j = 1; j < m; j++) {
            cout << ' ' << v[i][j];
        }
        cout << "\n";
    }

    // notes: my intuition was actually very close (it was correct), however I didn't step back from the observation about how 
    //        a given value "isn't used again" in my solution, all I needed was this observation not the rest of my idea. In the future,
    //        try to be even more rudimentary, seems to be a reoccuring problem

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