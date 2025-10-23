#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    unordered_map<int, int> mp;
    set<int> s;
    for (int x : v) {
        if (mp.find(x) == mp.end()) mp[x] = 1;
        else mp[x]++;
        s.insert(x);
    }
    for (int x : s) {
        if (mp[x] >= 2) {
            ans += mp[x] / 2;
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