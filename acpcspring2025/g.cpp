#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\g.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        unordered_map<int,vector<int>> mp;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]].push_back(i);
        }
        int ans = 0, strength = 1, index = mp[1].front();
        while (strength < m) {
            if (mp[strength + 1].front() > index) {
                index = mp[strength + 1].front();
            }
            else if (mp[strength + 1].back() < index) {
                index = mp[strength + 1].front();
                ans++;
            }
            else {
                index = *upper_bound(mp[strength + 1].begin(), mp[strength + 1].end(), index);
                ans++;
            }
            strength++;
        }
        if (index != n - 1) ans++;
        cout << ans;
    }
}