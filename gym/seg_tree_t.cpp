#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\seg_tree_t.exe

// Segment tree structure
struct Segment {
    ll sum, lazy;
} segm_tree[4 * 100000]; // Adjust size to handle maximum constraints

// Propagation function to handle lazy updates
void propagate(ll node, ll left, ll right) {
    segm_tree[node].sum += (right - left + 1) * segm_tree[node].lazy;
    if (left < right) { // Not a leaf node
        segm_tree[2 * node + 1].lazy += segm_tree[node].lazy;
        segm_tree[2 * node + 2].lazy += segm_tree[node].lazy;
    }
    segm_tree[node].lazy = 0; // Clear lazy value after propagation
}

// Update function to apply range updates
void update(ll node, ll left, ll right, ll x, ll y, ll value) {
    propagate(node, left, right);
    if (x > right || y < left) return; // No overlap
    if (x <= left && right <= y) { // Complete overlap
        segm_tree[node].lazy += value;
        propagate(node, left, right);
        return;
    }
    // Partial overlap
    ll middle = (left + right) / 2;
    update(2 * node + 1, left, middle, x, y, value);
    update(2 * node + 2, middle + 1, right, x, y, value);
    segm_tree[node].sum = segm_tree[2 * node + 1].sum + segm_tree[2 * node + 2].sum;
}

// Query function to calculate range sum
ll query(ll node, ll left, ll right, ll x, ll y) {
    propagate(node, left, right);
    if (x > right || y < left) return 0; // No overlap
    if (x <= left && right <= y) return segm_tree[node].sum; // Complete overlap
    // Partial overlap
    ll middle = (left + right) / 2;
    return query(2 * node + 1, left, middle, x, y) +
           query(2 * node + 2, middle + 1, right, x, y);
}

// Build function to initialize the segment tree
void build(vector<ll>& v, ll node, ll left, ll right) {
    if (left == right) {
        segm_tree[node].sum = v[left];
        return;
    }
    ll middle = (left + right) / 2;
    build(v, 2 * node + 1, left, middle);
    build(v, 2 * node + 2, middle + 1, right);
    segm_tree[node].sum = segm_tree[2 * node + 1].sum + segm_tree[2 * node + 2].sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    build(v, 0, 0, n - 1); // Build the segment tree

    for (ll i = 0; i < m; i++) {
        ll op;
        cin >> op;

        if (op == 1) { // Update operation: set element at index l to value r
            ll l, r;
            cin >> l >> r;
            update(0, 0, n - 1, l, l, r - v[l]); // Update difference
            v[l] = r; // Update array to reflect changes
        } else if (op == 2) { // Query operation: find sum on range [l...r)
            ll l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r - 1) << "\n";
        }
    }
}