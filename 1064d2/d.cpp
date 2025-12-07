#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe
// g++ d.cpp -o d

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    int MOD = 998244353;
    while (tt--) {
        // how many times can an element be a mode of any subset?
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> c(n + 1, 0);
        for (int i = 0; i < n; i++) {
            c[v[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            
        }
        cout << ans << "\n";
    }
}