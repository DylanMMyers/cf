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
        sort(v.begin(), v.end());
        ll mini = v[0];
        // two cases, mini exists twice where its easy
        // or mini exists once, and we have to find two numbers whos gcd is mini or else not possible
        if (v[0] == v[1]) cout << "YES\n";
        else {
            vector<ll> modm;
            for (int i = 1; i < n; i++) {
                if (v[i] % v[0] == 0) modm.push_back(v[i]);
            }
            if (modm.size() == 0) {
                cout << "NO\n";
                continue;
            }
            ll res = modm[0];
            for (int i = 1; i < modm.size(); i++) {
                res = __gcd(res, modm[i]);
            }
            if (res == v[0]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}