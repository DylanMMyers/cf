#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }
        if (n == 1) {
            cout << v[i].first << ' ' << v[i].second << "\n";
            continue;
        }
        
    }
}