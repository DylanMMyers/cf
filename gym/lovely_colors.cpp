#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\lovely_colors.exe

vector<vector<int>> graph;
vector<int> c, d;
vector<set<int>*> subtree;

void dfs(int i, int parent = -1) {
    int largest = -1;
    vector<int> children;
    for (int node : graph[i]) {
        if (node != parent) {
            dfs(node, i);
            children.push_back(node);
            if (largest == -1 || subtree[largest]->size() < subtree[node]->size()) largest = node;
        }
    }

    if (largest == -1) subtree[i] = new set<int>;
    else subtree[i] = subtree[largest];

    for (int child : children) {
        if (child == largest) continue;
        subtree[i]->insert(subtree[child]->begin(), subtree[child]->end());
    }
    subtree[i]->insert(c[i]);
    d[i] = subtree[i]->size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        c.resize(n);
        d.resize(n);
        graph.resize(n);
        subtree.resize(n, NULL);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        int a, b;
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        dfs(0, -1);

        for (int i = 0; i < n; i++) {
            cout << d[i] << ' ';
        }
    }
}