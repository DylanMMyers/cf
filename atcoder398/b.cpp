#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n = 7;
        vector<int> v(n);
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (mp.find(v[i]) != mp.end()) mp[v[i]]++;
            else mp[v[i]] = 1;
        }
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (f) break;
            for (int j = 0; j < n; j++) {
                if (v[j] == v[i]) continue;

                if ((mp[v[i]] >= 2 && mp[v[j]] >= 3) || (mp[v[i]] >= 3 && mp[v[j]] >= 2)) {
                    cout << "Yes";
                    f = true;
                    break;
                }
            }
        }
        if (!f) cout << "No";
    }
}