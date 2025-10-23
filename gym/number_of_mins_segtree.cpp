#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\number_of_mins_segtree.exe
vector<ll> A; // base array
vector<pair<ll,ll>> ST; // segtree (nodes)

void build(int node, int L, int R) {
    // Leaf node where L == R
    if (L == R) {
        ST[node] = {A[L], 1};
    }
    else {
        int mid = (L + R) / 2;
        build(2 * node + 1, L, mid);
        build(2 * node + 2, mid + 1, R);

        if (ST[2 * node + 1].first < ST[2 * node + 2].first) ST[node] = {ST[2 * node + 1].first, ST[2 * node + 1].second};
        else if (ST[2 * node + 1].first > ST[2 * node + 2].first) ST[node] = {ST[2 * node + 2].first, ST[2 * node + 2].second};
        else ST[node] = {ST[2 * node + 1].first, ST[2 * node + 1].second + ST[2 * node + 2].second};
    }
}

void update(int node, int L, int R, int idx, int val) {
    if (L == R) {
        A[idx] = val; // UPDATE THIS TO CHANGE WITH DESIRED UPD
        ST[node] = {val, 1};
    }
    else {
        int mid = (L + R) / 2;
        if (L <= idx && idx <= mid) update(2 * node + 1, L, mid, idx, val);
        else update(2 * node + 2, mid + 1, R, idx, val);

        if (ST[2 * node + 1].first < ST[2 * node + 2].first) ST[node] = {ST[2 * node + 1].first, ST[2 * node + 1].second};
        else if (ST[2 * node + 1].first > ST[2 * node + 2].first) ST[node] = {ST[2 * node + 2].first, ST[2 * node + 2].second};
        else ST[node] = {ST[2 * node + 1].first, ST[2 * node + 1].second + ST[2 * node + 2].second};
    }
}

pair<ll,ll> query(int node, int tl, int tr, int l, int r) {
    if (r < tl || tr < l) return {INT_MAX, 1};
    if (l <= tl && tr <= r) return ST[node];
    int tm = (tl + tr) / 2;
    pair<ll,ll> left, right;
    left = query(2 * node + 1, tl, tm, l, r);
    right = query(2 * node + 2, tm + 1, tr, l, r);
    if (left.first < right.first) return left;
    else if (right.first < left.first) return right;
    else return {left.first, left.second + right.second};
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
    pair<ll,ll> curr;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> idx >> v;
            update(0, 0, n - 1, idx, v);
        }
        else {
            cin >> l >> r;
            curr = query(0, 0, n - 1, l, r - 1);
            cout << curr.first << ' ' << curr.second << "\n";
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