#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (mp.find(v[i]) != mp.end()) mp[v[i]]++;
            else mp[v[i]] = 1;
        }
        int ans = -1, idx = 0;
        for (int i = 0; i < n; i++) {
            if ((mp[v[i]] == 1) && (v[i] > ans)) {
                idx = i;
                ans = v[i];
            }
        }
        if (ans > -1) cout << idx + 1;
        else cout << -1;
    }
}