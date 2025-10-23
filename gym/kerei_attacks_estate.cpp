#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\kerei_attacks_estate.exe

void dfs(int parent, int node, pair<ll,ll> currsum, vector<ll>& ans, vector<int>& v, vector<vector<int>>& al, bool which) {
    ll maxi1 = 0, maxi2 = 0;
    currsum.first += (which ? 1 : -1) * v[node];
    currsum.second += (which ? -1 : 1) * v[node];
    ans[node] = (which ? currsum.first : currsum.second);
    currsum.first = max(currsum.first, 0ll);
    currsum.second = max(currsum.second, 0ll);
    for (int i = 0; i < al[node].size(); i++) {
        if (al[node][i] == parent) continue;
        dfs(node, al[node][i], currsum, ans, v, al, !which);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        vector<vector<int>> al(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y; cin >> x >> y;
            x--;
            y--;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        // can just store both if the curr was pos or negative on the threat line
        vector<ll> ans(n);
        dfs(-1, 0, {0, 0}, ans, v, al, true);
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
    }
}

// easy problem, just missread the vertical definition
// for lengthy cf problem desc, ensure you understand exactly what you're doing without a doubt