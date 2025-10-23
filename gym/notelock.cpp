#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\notelock.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int idx = 0, ans = 0, c = 0;
        while (idx < n && s[idx] == '0') {
            idx++;
        }
        while (idx < n) {
            if (s[idx] == '1') {
                if (c <= 0) ans++;
                c = k;
            }
            c--;
            idx++;
        }
        cout << ans << "\n";
    }
}