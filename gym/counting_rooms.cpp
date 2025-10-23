#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\counting_rooms.exe

void dfs(vector<string>& v, int i, int j) {
    if (v[i][j] == '#') return; // wall, not relevant
    // otherwise we keep searching and marking
    v[i][j] = '#';
    if (i < v.size() - 1) dfs(v, i + 1, j);
    if (i > 0) dfs(v, i - 1, j);
    if (j < v[0].length() - 1) dfs(v, i, j + 1);
    if (j > 0) dfs(v, i, j - 1);
}

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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '.') {
                    dfs(v, i, j);
                    ans++;
                }
            }
        }
        cout << ans;
    }
}