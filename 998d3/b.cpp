#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
    }

    int chase;
    for (int i = 0; i < n; i++) {
        chase = v[i][0];
        for (int j = 1; j < m; j++) {
            if (chase + n != v[i][j]) {
                cout << -1 << "\n";
                return;
            }
            chase += n;
        }
        if (v[i][0] < n) ans[v[i][0]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << "\n";

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