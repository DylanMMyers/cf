#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\distinct_colors.exe
// g++ distinct_colors.cpp -o distinct_colors

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<set<int>> tree(n + 1);
    vector<vector<int>> al(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        tree[i].insert(x);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    function<void(int, int)> dfs = [&](int node, int prev) {
        for (int x : al[node]) {
            if (x == prev) continue;
            dfs(x, node);
            if (tree[x].size() > tree[node].size()) swap(tree[x], tree[node]);
            for (int y : tree[x]) {
                tree[node].insert(y);
            }
        }
        ans[node] = tree[node].size();
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

// solve each subproblem/subtree using dfs, store answer in vector (as it may be changed in future ops)
// use small to large merging, where for each child in nodes subtree, merge smaller subtree into larger (use swap)
// O(nlog^2n) -> with small to large, nodes move at most logn times, logn time complexity per move for using set