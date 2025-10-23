#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\maximize_root.exe

ll dfs(int node, vector<vector<int>>& al, vector<ll>& v) {
    ll mini = LLONG_MAX;
    for (int i = 0; i < al[node].size(); i++) {
        mini = min(mini, dfs(al[node][i], al, v));
    }
    if (mini == LLONG_MAX) return v[node];
    if (mini < v[node]) return mini;
    return (mini + v[node]) / 2; // not always true, if the subtree value is less than the curr value, the subtree value must be used
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        vector<vector<int>> al(n);
        for (int i = 1; i <= n - 1; i++) {
            int x; cin >> x;
            x--;
            al[x].push_back(i);
        }
        ll mins = LLONG_MAX;
        for (int i = 0; i < al[0].size(); i++) {
            mins = min(mins, dfs(al[0][i], al, v));
        }
        if (mins == LLONG_MAX) {
            cout << v[0] << "\n";
            continue;
        }
        cout << v[0] + mins << "\n";
    }
}