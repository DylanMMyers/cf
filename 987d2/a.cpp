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
    unordered_map<int, int> mp;
    for (int x : v) {
        if (mp.find(x) == mp.end()) mp[x] = 1;
        else mp[x]++;
    }
    int maxi = -1;
    for (int x : v) {
        maxi = max(maxi, mp[x]);
    }
    cout << n - maxi << "\n";
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