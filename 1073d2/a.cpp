#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe
// g++ a.cpp -o a

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<pair<int,int>> vn;
        for (int i = 0; i < n; i++) {
            if (i % 2) vn.push_back(make_pair(v[i], 0));
            else vn.push_back(make_pair(v[i], 1));
        }
        sort(vn.begin(), vn.end());
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (vn[i].second == vn[i - 1].second) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}