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
        int n;
        cin >> n;
        unordered_map<int, vector<int>> al;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        vector<int> res;
        
        // we always have to select the current longest path with some apples on it
        // must be completely unvisited nodes
        // can we make a pq and push all bfs routes to them? then while not every node is visited we can continue

        // can it be said that if there is a longest path, the endpoints will be "unique"? As in we cant label them however we want
        // guaranteed to form a tree
        // so, we can just repeatedly find the longest paths and search?
        // is it a game of finding the largest strongly connected component and removing it repeatedly until graph is empty?
        // no, we just find curr largest path and mark it all as visited, then continue down each subtree until we have visited every node
        // break ties in length with max node #
        
        int maxlen = 0;
    }
}