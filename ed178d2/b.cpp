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
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<ll> maxi(n + 1, -1), mini(n + 1, 1e9 + 1), ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            maxi[i] = max(maxi[i - 1], v[i - 1]);
        }
        for (int i = n; i > 0; i--) {
            mini[i] = min(mini[i - 1], v[i - 1]);
            if (i != n) ps[i] = ps[i + 1] + v[i];
        }
        ps[0] = v[0] + ps[1];
        // main logic
        for (int i = n; i > 0; i--) {
            ll curr = ps[i - 1];
            if (maxi[i] > mini[i]) curr = curr - mini[i] + maxi[i];
            cout << curr << " \n"[i == 1];
        }
    }
}