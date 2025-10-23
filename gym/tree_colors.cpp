#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\distinct_colors.exe

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
        ST[node] = ST[2 * node + 1] + ST[2 * node + 2];
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
        ST[node] = ST[2 * node + 1] + ST[2 * node + 2];
    }
}

ll query(int node, int tl, int tr, int l, int r) {
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return ST[node];
    int tm = (tl + tr) / 2;
    return query(2 * node + 1, tl, tm, l, r) + query(2 * node + 2, tm + 1, tr, l, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        
    }
}