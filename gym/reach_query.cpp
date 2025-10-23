#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\reach_query.exe

class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    // can we just store the connected components and count of their black nodes
    vector<int> color(n + 1, 0), count(n + 1, 0); // 0 means white, 1 means black
    DisjointSets dsu(n + 1);
    for (int i = 0; i < q; i++) {
        int type, u, v; cin >> type;
        if (type == 1) {
            cin >> u >> v;
            u = dsu.find(u);
            v = dsu.find(v);
            if (dsu.connected(u, v)) continue;
            // my key mistake is that unite doesnt guarantee that u or v will be the parent of the new unity????
            dsu.unite(u, v);
            int k = dsu.find(u);
            // ahh, it will be either u or v (non deterministic) so we can just:
            if (k == u) count[u] += count[v];
            else count[v] += count[u];
        }
        else if (type == 2) {
            cin >> v;
            count[dsu.find(v)] -= color[v];
            color[v] = !(color[v]);
            count[dsu.find(v)] += color[v];
        }
        else {
            cin >> v;
            if (count[dsu.find(v)]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
// so my soln correct down to the t on the editorial except i used dsu wrong for type 1 lol