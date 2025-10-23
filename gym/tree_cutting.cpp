#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\tree_cutting.exe

bool helper() {
    // check if a current k value is valid using greedy dfs

}

void solve() {
    int n, k, u, v;
    cin >> n >> k;
    vector< vector<int> > al(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        al[u - 1].push_back(v - 1);
        al[v - 1].push_back(u - 1);
    }

    // so for the optimal solution:
    // binary search for some value of x that supports subtrees with a least k values
    // we verify a certain state of k by doing a greedy bfs (if we find a subtree that possesses >= k nodes, it's valid)
    // this greedy approach works because if we were to have any way to split a tree into subtrees, it would work greedily
    // if we can verify a state of k, increase k according to binary search
    // this is the logic behind the solution

    // my code:

    // WIP
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