#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\o.exe

class DisjointSets {
    private:
        vector<int> parents;
        vector<int> sizes;
   
    public:
        DisjointSets(int size) : parents(size), sizes(size, 1) {
            for (int i = 0; i < size; i++) { parents[i] = i; }
        }
    
        /** @return the "representative" node in x's component */
        int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }
    
        /** @return whether the merge changed connectivity */
        bool unite(int x, int y) {
            int x_root = find(x);
            int y_root = find(y);
            if (x_root == y_root) { return false; }
    
            if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
            sizes[x_root] += sizes[y_root];
            parents[y_root] = x_root;
            return true;
        }
    
        /** @return whether x and y are in the same connected component */
        bool connected(int x, int y) { return find(x) == find(y); }
};
unordered_map<int,vector<int>> al;
vector<int> visited;
vector<int> v;

bool helper(int node, int parent) {
    if (visited[node]) return true;
    visited[node] = 1;
    bool ans = true;
    for (int i = 0; i < al[node].size(); i++) {
        if (al[node][i] == parent) continue;

        if (v[al[node][i]] != v[node]) {
            ans = false;
            break;
        }

        ans = helper(al[node][i], node);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, m, c;
        cin >> n >> m >> c;
        v.resize(n);
        DisjointSets dsug(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i]--;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            al[a].push_back(b);
            al[b].push_back(a);
            dsug.unite(a, b);
        }
        if (!m) {
            int x = v.front();
            bool f = false;
            for (int i = 1; i < n; i++) {
                if (v[i] != x) {
                    cout << -1;
                    f = true;
                    break;
                }
            }
            if (!f) cout << 0;
            break;
        }
        // find all the common wool colors across sets
        // go and rank each sheeps current influence (total sets which have entirely sheep of wool color c_i)
        // then, ans is # of sets - max(influence)
        // if no common sheep, -1
        unordered_map<int,set<int>> setcolors;
        set<int> parents;
        for (int i = 0; i < n; i++) {
            setcolors[dsug.find(i)].insert(v[i]);
            parents.insert(dsug.find(i));
        }
        vector<int> ps;
        for (auto it : parents) {
            ps.push_back((int)it);
        }
        vector<int> colorcounting(c, 0);
        for (int i = 0; i < ps.size(); i++) {
            for (auto it : setcolors[ps[i]]) {
                colorcounting[(int)it]++;
            }
        }
        vector<int> validcolors;
        for (int i = 0; i < c; i++) {
            if (colorcounting[i] == ps.size()) validcolors.push_back(i);
        }
        if (!validcolors.size()) {
            cout << "-1";
            break;
        }
        vector<int> validcolorinfluence(c, 0);
        for (int i = 0; i < ps.size(); i++) {
            if (helper(ps[i], ps[i])) validcolorinfluence[v[ps[i]]]++;
        }
        auto max_ele_it = max_element(validcolorinfluence.begin(), validcolorinfluence.end());
        cout << ps.size() - (int)*max_ele_it;
    }
}