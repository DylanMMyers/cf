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
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        if (n == 1) {
            cout << (v[0] == k ? 1 : 0) << "\n";
            continue;
        }
        vector<int> c(n + 1, 0);
        for (int i = 0; i < n; i++) c[v[i]]++;
        int ans = 0, carry = 0;
        for (int i = 0; i < k; i++) {
            if (!c[i]) ans++;
        }        
        cout << max(ans, c[k]) << "\n";
    }
}