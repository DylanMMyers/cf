#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe
// g++ f.cpp -o f

// we can root the tree from some arbitrary node and dfs to find the size of each nodes subtree
// then, we iterate back over each node and check the following conditions about how i's subtree contribute to others:
// if n - subtree_size(i) >= k, the count of nodes not in the subtree, then we know that every node in the subtree will have 
// i contribute 1 to its score as every root in the subtree would have a subtree of size >= k from i 
// if subtree_size(i) >= k, then we know all nodes not in the subtree would gain a score of 1 from i as all trees rooted at
// some node not in i's subtree would have a subtree of size >= k rooted at i
// finally, we add n to our answer as since we only check how i will contribute to other subtrees and not itself, we must handle
// the node itself: i will always contribute 1 to itself as it's subtree is size n, k can't be greater than n so it holds

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> al(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--;
            v--;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        vector<int> c(n, 1);
        auto dfs = [&](auto &dfs, int node, int parent) -> void {
            for (int next : al[node]) {
                if (next != parent) {
                    dfs(dfs, next, node);
                    c[node] += c[next];
                }
            }
        };
        dfs(dfs, 0, -1);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] >= k) ans += n - c[i];
            if (n - c[i] >= k) ans += c[i];
        }
        cout << ans + n << "\n";
    }
}