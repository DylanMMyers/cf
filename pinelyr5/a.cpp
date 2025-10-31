#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe
// g++ a.cpp -o a

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int r, x, d, n; cin >> r >> x >> d >> n;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans++;
                r -= d;
            }
            else if (r < x) {
                ans++;
                r -= d;
            }
        }
        cout << ans << "\n";
    }
}