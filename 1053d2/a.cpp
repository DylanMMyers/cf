#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> v(m);
        for (int i = 0; i < m; i++) cin >> v[i];
        int ans = 1, resets = 0;
        for (int i = 1; i < m; i++) {
            if (v[i] != (v[i - 1] + 1)) resets++;
        }
        if (!resets) ans = n - v.back() + 1; 
        cout << ans << "\n";
    }
}