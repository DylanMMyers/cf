#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a_path_in_dict.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<pair<int,int>> v(n); for (int i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
        vector<vector<int>> al;
        for (int i = 0; i < m; i++) {
            al[v[i].first].push_back(v[i].second);
            al[v[i].second].push_back(v[i].first);
        }
        // what happens if we greedily visit the min node from our curr node repeatedly without visiting duplicate nodes
        // then we recursively backtrack*, and the first time we reach y we have our ans?
        // *when we backtrack, we go back to previous node and mark the curr as visited and not complete, then continue
        // is this n^2?
        // *when we say we want to visit a node, if we are between selecting a node with val of larger than y val, we should just go to y and conclude the search
        // can use a greedy dfs and reference to a stack to store the nodes we travelled on, then when we reach y successfully lets return the travel in the stack
        
    }
}