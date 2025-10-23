#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\e.exe

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

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    set<pair<int, int>> F, G;
    pair<int,int> x = {};
    DisjointSets dsuF(n + 1);
    for (int i = 0; i < m1; i++) {
        cin >> x.first >> x.second;
        if (x.first > x.second) swap(x.first, x.second);
        F.insert(x);
        dsuF.unite(x.first, x.second);
    }
    DisjointSets dsuG(n + 1);
    for (int i = 0; i < m2; i++) {
        cin >> x.first >> x.second;
        if (x.first > x.second) swap(x.first, x.second);
        G.insert(x);
        dsuG.unite(x.first, x.second);
    }

    // before we search, must see if there is a path so use dsu to see if we can reach desired node:
    // F = 1 -> 2, 2 -> 3 
    // G = 1 -> 3 doesnt work
    // however,
    // F = 1 -> 3
    // G = 1 -> 2, 2 -> 3 should work (or rather 0 operations needed here vs 3 before)
    
    int ans = 0;
    for (auto x : F) {
        if (!(dsuG.connected(x.first, x.second))) {
            F.erase(x);
            ans++;
        }
    }

    set<int> a, b;
    for (auto x : F) {
        a.insert(dsuF.find(x.first));
    }
    for (auto x : G) {
        b.insert(dsuG.find(x.first));
    }

    if (b.size() > a.size()) ans += b.size() - a.size();

    cout << ans << "\n";
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