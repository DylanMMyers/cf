#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (mp.find(v[i]) == mp.end()) mp[v[i]] = 1;
            else mp[v[i]]++;
        }
        int l = -1, r = -1, len = 0, currlen = 0;
        for (int i = 0; i < n; i++) {
            if (mp[v[i]] == 1) currlen++;
            else currlen = 0;

            if (currlen > len) {
                r = i;
                l = i - currlen + 1;
                len = currlen;
            }
        }
        if (r == -1 && l == -1) cout << "0\n";
        else cout << l + 1 << ' ' << r + 1 << "\n";
    }
}