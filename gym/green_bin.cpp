#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\green_bin.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        unordered_map<string,int> mp;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            sort(s.begin(), s.end());
            if (mp.find(s) != mp.end()) {
                ans += mp[s];
                mp[s]++;
            }
            else mp[s] = 1;
        }
        cout << ans;
    }
}