#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<ll> a(n);
        a[0] = 1;
        ll it = 1;
        for (int i = 1; i < n; i++) {
            ll x = v[i] - v[i - 1] - 1;
            if (it <= x) a[i] = ++it;
            else a[i] = it - x;
        }
        for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
    }
}