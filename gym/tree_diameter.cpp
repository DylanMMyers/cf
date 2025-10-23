#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\tree_diameter.exe

unordered_map<int,vector<int>> al;
vector<int> v;
int ans = 0;

void dfs(int curr, int prev) {
    if (al[curr].size() == 1 && al[curr][0] == prev) {
        v[curr] = 1;
        ans = max(ans, 1);
        return;
    }

    for (int i = 0; i < al[curr].size(); i++) {
        if (al[curr][i] == prev) continue;
        dfs(al[curr][i], curr);
    }
    
    int x = 0, y = 0;
    for (int i = 0; i < al[curr].size(); i++) {
        if (v[al[curr][i]] >= x) {
            y = x;
            x = v[al[curr][i]];
        }
        else if (v[al[curr][i]] >= y) y = v[al[curr][i]];
    }

    ans = max(ans, 1 + x + y);
    v[curr] = max(1 + x, 1 + y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        v.resize(n + 1);
        fill(v.begin(), v.end(), 0);
        dfs(1, 0);
        cout << ans - 1;
    }
}