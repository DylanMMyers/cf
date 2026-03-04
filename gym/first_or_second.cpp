#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\first_or_second.exe
// g++ first_or_second.cpp -o first_or_second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<ll> ips(n + 1, 0), ps(n + 1, 0);
        ps[1] = v[0];
        ips[1] = -1 * v[0];
        for (int i = 2; i <= n; i++) {
            ips[i] = ips[i - 1] - v[i - 1];
            ps[i] = ps[i - 1] + abs(v[i - 1]);
        }  
        ll ans = -1e18;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, ps[i - 1] + (ips[n] - ips[i]));
        }
        cout << ans << "\n";
    }
}