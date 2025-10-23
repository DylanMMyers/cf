#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    if (n == 1) {
        cout << v[0];
        return;
    }
    int vouchers = (v[0] != v[1]), newvouchers = (v[0] == v[1]);
    ll cost = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            if (vouchers > 0) vouchers--;
            else {
                cost += v[i];
                newvouchers++;
            }
        }
        else {
            vouchers += newvouchers;
            newvouchers = 0;
            if (vouchers > 0) vouchers--;
            else {
                cost += v[i];
                newvouchers++;
            }
        }
    }
    cout << cost;
}

int main() {
    solve();
}