#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\range_upd_queries.exe

struct FT {
	vector<ll> s;
    ll sz;
	FT(int n) : s(n), sz(n) {}
	void upd(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz; pos |= pos + 1) s[pos] += dif;
	}
    void range_upd(int l, int r, ll dif) {
        upd(l, dif);
        if (r + 1 < sz) upd(r + 1, -dif);
    }
    ll point_query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos >= 0; pos = (pos & (pos + 1)) - 1) res += s[pos];
		return res;
	}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    FT ft = FT(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ft.range_upd(i, i, x);
    }
    for (int i = 0; i < q; i++) {
        int o; cin >> o;
        if (o == 1) {
            int a, b, diff; cin >> a >> b >> diff;
            a--;
            b--;
            ft.range_upd(a, b, diff);
        }
        else {
            int k; cin >> k;
            k--;
            cout << ft.point_query(k) << "\n"; 
        }
    }
}