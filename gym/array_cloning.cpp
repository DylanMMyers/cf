#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\array_cloning.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        unordered_map<ll, ll> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(v[i]) == mp.end()) mp[v[i]] = 1;
            else mp[v[i]]++;
        }
        ll maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, mp[v[i]]);
        }
        if (maxi == n) {
            cout << "0\n";
            continue;
        }
        ll ans = n - maxi;
        ll sum = maxi;
        while (sum < n) {
            sum *= 2;
            ans++;
        }
        cout << ans << "\n";
    }
}