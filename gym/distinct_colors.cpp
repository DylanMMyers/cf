#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\distinct_colors.exe

vector<int> ans;
unordered_map<int,set<int>> tree;
unordered_map<int,vector<int>> al;

void dfs(int curr, int prev) {
    for (int x : al[curr]) {
        if (x == prev) continue;
        dfs(x, curr);
        if (tree[x].size() > tree[curr].size()) swap(tree[x], tree[curr]);
        for (auto ele : tree[x]) {
            tree[curr].insert(ele);
        }
    }
    ans[curr] = tree[curr].size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int z;
            cin >> z;
            tree[i].insert(z);
        }
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        ans.resize(n + 1);
        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
    }
}