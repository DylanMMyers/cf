#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c2.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (v[i - 1] < 0) ps[i] = ps[i - 1] - v[i - 1];
            else ps[i] = ps[i - 1] + v[i - 1]; 
        }
        ll ans = 0, lneg = 0, lpos = 0, lovr = 0;
        int l = 0, r = n - 1;
        while (v[l] >= 0) {
            
        }
    }
}