#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    unordered_map<int, int> mp;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (mp.find(x) == mp.end()) mp[x] = 1, v.push_back(x);
        else mp[x]++;
    }
    int ans = 0;
    n = v.size();
    for (int i = 0; i < n; i++) {
        if (mp.find(k - v[i]) != mp.end()) {
            int mini = min(mp[v[i]], mp[k - v[i]]);
            if (v[i] == (k - v[i])) mini /= 2;
            ans += mini;
            mp[v[i]] -= mini;
            mp[k - v[i]] -= mini;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}