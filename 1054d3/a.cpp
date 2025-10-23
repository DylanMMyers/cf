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
        int n; cin >> n;
        int ans = 0, ne = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == -1) ne++;
            if (x == 0) ans++;
        }
        cout << ans + (ne % 2 ? 2 : 0) << "\n";
    }
}