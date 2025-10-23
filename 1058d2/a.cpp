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
        vector<int> v(n), c(101, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            c[v[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < 101; i++) {
            if (!c[i]) {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
}