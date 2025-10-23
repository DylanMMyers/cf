#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += v[i];
        }
        if (ans % x == 0 && ans / x == n) cout << "YES\n";
        else cout << "NO\n";
    }
}