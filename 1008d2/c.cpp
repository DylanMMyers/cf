#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        n *= 2;
        vector<int> v(n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            s.insert(v[i]);
        }        
        sort(v.rbegin(), v.rend());
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) ans += v[i];
            else ans -= v[i];
        }
        
    }
}