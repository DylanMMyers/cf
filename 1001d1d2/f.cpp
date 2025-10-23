#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    unordered_map<int, vector<int>> alw;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            alw[i].push_back(max(v[i].first + v[j].second, v[i].second + v[j].first));
        }
    }
    for (int k = 2; k < n; k++) {
        
    }
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