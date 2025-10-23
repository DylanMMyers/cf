#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int,int>> v(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> v[i].first >> v[i].second;
            v[i].first--;
            v[i].second--;
        }
        if (n == 2) {
            cout << "0\n";
            continue;
        }
        unordered_map<int, vector<int>> al;
        for (int i = 0; i < n - 1; i++) {
            al[v[i].first].push_back(v[i].second);
            al[v[i].second].push_back(v[i].first);
        }
        // dont need to dfs, need to count leaves (i was doing that originally by dfs, kind of dumb)
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (al[i].size() == 1);
        }
        // now, the most efficient way is to go from soem node to all the leaves, which means the node connected to the most leaves is the optimal starting point
        // so we find this node, then subtract the leaves its connected to from the total leaves and thats the ans
        int maxc = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < al[i].size(); j++) {
                c += (al[al[i][j]].size() == 1);
            }
            maxc = max(maxc, c);
        }
        cout << ans - maxc << "\n";
    }
}