#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\salary_queries.exe
vector<ll> A; // base array
vector<pair<ll,ll>> ST; // segtree (nodes)

void build(int node, int l, int r) {
    // Leaf node where L == R
    if (l == r) ST[node] = {A[l], A[l]};
    else {
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
        // set range min
        if (ST[2 * node + 1].first < ST[2 * node + 2].first) ST[node].first = ST[2 * node + 1].first;
        else ST[node].first = ST[2 * node + 2].first;
        // set range max
        if (ST[2 * node + 1].second > ST[2 * node + 2].second) ST[node].second = ST[2 * node + 1].second;
        else ST[node].second = ST[2 * node + 2].second;
    }
}

void update(int node, int l, int r, ll k, ll x) {
    if (l == r) {
        A[k] = x; // UPDATE THIS TO CHANGE WITH DESIRED UPD
        ST[node] = {x, x};
    }
    else {
        int mid = (l + r) / 2;
        if (l <= k && k <= mid) update(2 * node + 1, l, mid, k, x);
        else update(2 * node + 2, mid + 1, r, k, x);

        // check range min
        if (ST[2 * node + 1].first < ST[2 * node + 2].first) ST[node].first = ST[2 * node + 1].first;
        else ST[node].first = ST[2 * node + 2].first;
        // check range max
        if (ST[2 * node + 1].second > ST[2 * node + 2].second) ST[node].second = ST[2 * node + 1].second;
        else ST[node].second = ST[2 * node + 2].second;
    }
}

ll query(int node, int l, int r, ll a, ll b) {
    if (ST[node].first >= a && ST[node].second <= b) return r - l + 1;
    if (l == r) return 0;
    int mid = (r + l) / 2;
    return query(2 * node + 1, l, mid, a, b) + query(2 * node + 2, mid + 1, r, a, b);
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
    char op;
    ll k, x, a, b;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == '!') {
            cin >> k >> x;
            update(0, 0, n - 1, k, x);
        }
        else {
            cin >> a >> b;
            cout << query(0, 0, n - 1, a, b) << "\n";
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