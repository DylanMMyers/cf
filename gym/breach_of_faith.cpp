#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\breach_of_faith.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> v(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        ll ans = 0;
        for (int i = 0; i < 2 * n; i++) {
            ans += v[i] * (ll)(i % 2 ? -1 : 1);
        }
        cout << -1 * ans << ' ';
        for (int i = 0; i < 2 * n; i++) {
            cout << v[i] << " \n"[i == 2 * n - 1];
        }
    }
}