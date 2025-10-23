#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        vector<int> pf(n + 1);
        for (int i = 1; i <= n; i++) {
            pf[i] = pf[i - 1] + v[i];
        }
        if (n % 2 == 0) {
            n++;
            int c = pf[n / 2] & 1;
            v.push_back(c);
            pf.push_back(pf.back() + c);
        }
        for (int i = n + 1; i <= n * 2; i++) {
            v.push_back(pf[i / 2] & 1);
            pf.push_back(pf[i - 1] + v[i]);
        }
        int p = pf[n] & 1;
        auto get = [&](ll x) {
            int res = 0;
            while (true) {
                if (x <= n * 2) {
                    res ^= v[x];
                    break;
                }
                res ^= p;
                if ((x / 2 - n) % 2 == 0) break;
                x /= 2;
            }
            return res;
        };
        cout << get(l) << "\n";
    }
}