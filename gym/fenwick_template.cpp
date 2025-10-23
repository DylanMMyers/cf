#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

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
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        
    }
}