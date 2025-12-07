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
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> pre(n + 1), suf(n + 1);
        int mini = 2 * 1e5 + 1, maxi = 0;
        for (int i = 0; i < n; i++) {
            mini = min(mini, v[i]);
            pre[i] = mini;
        }
        for (int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, v[i]);
            suf[i] = maxi;
        }
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (pre[i - 1] > suf[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}