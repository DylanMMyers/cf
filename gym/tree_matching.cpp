#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\tree_matching.exe

unordered_map<int,vector<int>> al;
vector<int> v;
int ans = 0;

void dfs(int curr, int prev) {
    // lets go to leaf nodes where its always optimal
    // then lets remove a leaf node and the node it is assigned to, this will always result in an optimal matching
    if (al[curr].size() == 1) {
        int x = al[curr][0];
        if (!v[x] && !v[curr]) {
            v[x] = -1;
            v[curr] = -1;
            ans++;
        }
        if (x == prev) return;
    }

    for (int i = 0; i < (int)al[curr].size(); i++) {
        if (al[curr][i] == prev) continue;
        dfs(al[curr][i], curr);
    }
    if (!v[curr] && !v[prev]) {
        v[curr] = -1;
        v[prev] = -1;
        ans++;
    }
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
        v[0] = -1;
        dfs(1, 0);
        cout << ans;
    }
}