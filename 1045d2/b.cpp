    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    // Get-Content t.txt | .\b.exe

    signed main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll tt = 1;
        cin >> tt;
        while (tt--) {
            ll n, k; cin >> n >> k;
            vector<ll> v(n);
            for (ll i = 0; i < n; i++) cin >> v[i];
            if (n == 1) {
                cout << v[0] + k << "\n";
                continue;
            }
            for (int i = 0; i < n; i++) {
                v[i] += k * (v[i] % (k + 1));
            }
            for (ll i = 0; i < n; i++) {
                cout << v[i] << " \n"[i == n - 1];
            }
        }
    }