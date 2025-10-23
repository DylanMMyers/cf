#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\seg_tree_for_min.exe
vector<ll> A, ST;

void build(int node, int L, int R) {
    // Leaf node where L == R
    if (L == R) {
        ST[node] = A[L];
    }
    else {
        int mid = (L + R) / 2;
        build(2 * node + 1, L, mid);
        build(2 * node + 2, mid + 1, R);
        ST[node] = min(ST[2 * node + 1], ST[2 * node + 2]);
    }
}

void update(int node, int L, int R, int idx, int val) {
    if (L == R) {
        A[idx] = val; // UPDATE THIS TO CHANGE WITH DESIRED UPD
        ST[node] = val;
    }
    else {
        int mid = (L + R) / 2;
        if (L <= idx && idx <= mid) update(2 * node + 1, L, mid, idx, val);
        else update(2 * node + 2, mid + 1, R, idx, val);
        ST[node] = min(ST[2 * node + 1], ST[2 * node + 2]);
    }
}

ll query(int node, int tl, int tr, int l, int r) {
    if (r < tl || tr < l) return INT_MAX;
    if (l <= tl && tr <= r) return ST[node];
    int tm = (tl + tr) / 2;
    return min(query(2 * node + 1, tl, tm, l, r), query(2 * node + 2, tm + 1, tr, l, r));
}

void solve() {
    int n, m;
    cin >> n >> m;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ST.resize(4 * n);
    build(0, 0, n - 1);
    int op, idx, v, l, r;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> idx >> v;
            update(0, 0, n - 1, idx, v);
        }
        else {
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r - 1) << "\n";
        }
    }
    A.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}