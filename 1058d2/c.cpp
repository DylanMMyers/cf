#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v;
        int sz = 0;
        for (int i = 0; i < 31; i++) {
            v.push_back((1 << i) & n ? 1 : 0);
            if (v.back() == 1) sz = i; 
        }
        for (int i = 0; i < 31; i++) {
            v.push_back(0);
        }
        bool ans = false;
        for (int i = sz; i < v.size(); i++) {
            if (!(i % 2) && v[i / 2]) continue;
            ans = true;
            for (int j = 0; j <= i; j++) {
                if (v[j] != v[i - j]) {
                    ans = false;
                    break;
                }
            }
            if (ans) break;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}