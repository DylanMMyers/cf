#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\minimal_grid_path.exe
// g++ minimal_grid_path.cpp -o minimal_grid_path

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // we can kind of just do greedy path, when we reach a split we can iterate along the diagonal
    // along this diagonal, we continue iterating until we have a definitive node we want to reach
    // until we reach either the end or a letter which is uniquely the smallest we continue adding one of the
    // letter from the diagonal to the ans, then we continue this until we reach (n, n)
    // then, return our made string
    // O(n^2)
    // ensure we jump down to the end or the unique diagonal entry before continuing
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    string ans = "";
    int i = 0, j = 0;
    while (i < n && j < n) {
        ans += ans[i][j];
        if (i + 1 < n && j + 1 < n) {
            if (v[i + 1][j] == v[i][j + 1]) {
                // handle diagonal traversal logic here
                // need to go all the way down valid diagonals until unique lesser value is reached
                // then, update i,j and ans string

            }
            else if (v[i + 1][j] < v[i][j + 1]) i++;
            else j++;
        }
        else if (i + 1 < n) i++;
        else j++;
    }
    cout << ans;
}