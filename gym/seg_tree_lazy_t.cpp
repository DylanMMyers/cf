#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\seg_tree_lazy_t.exe

struct S { ll sum, add, set; bool has_set; } t[800005];

void push(int n, int l, int r) {
    if (t[n].has_set) {
        t[n].sum = (r - l + 1) * t[n].set;
        if (l < r) {
            for (int c : {2*n+1, 2*n+2}) {
                t[c].set = t[n].set;
                t[c].has_set = 1;
                t[c].add = 0;
            }
        }
        t[n].has_set = 0;
    }
    if (t[n].add) {
        t[n].sum += (r - l + 1) * t[n].add;
        if (l < r) {
            t[2*n+1].add += t[n].add;
            t[2*n+2].add += t[n].add;
        }
        t[n].add = 0;
    }
}

void upd(int n, int l, int r, int x, int y, ll v, bool is_set) {
    push(n, l, r);
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
        if (is_set) t[n].set = v, t[n].has_set = 1, t[n].add = 0;
        else t[n].add += v;
        push(n, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2*n+1, l, m, x, y, v, is_set);
    upd(2*n+2, m+1, r, x, y, v, is_set);
    t[n].sum = t[2*n+1].sum + t[2*n+2].sum;
}

ll qry(int n, int l, int r, int x, int y) {
    push(n, l, r);
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return t[n].sum;
    int m = (l + r) / 2;
    return qry(2*n+1, l, m, x, y) + qry(2*n+2, m+1, r, x, y);
}

void build(vector<ll>& v, int n, int l, int r) {
    if (l == r) { t[n].sum = v[l]; return; }
    int m = (l + r) / 2;
    build(v, 2*n+1, l, m); build(v, 2*n+2, m+1, r);
    t[n].sum = t[2*n+1].sum + t[2*n+2].sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    build(v, 0, 0, n - 1); // Build the segment tree
}