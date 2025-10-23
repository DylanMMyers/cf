#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<int> c(n + 1, 0);
        for (int i = 0; i < n; i++) {
            c[v[i]]++;
        }
        sort(c.begin(), c.end());
        ll x = 0, ans = 0;
        for (int i = n; i > 0; i--) {
            if (!c[i]) break;

            ans = max(ans, c[i] + x * c[i]);
            x++;
        }
        cout << ans << "\n";
    }
}