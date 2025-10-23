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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        if (s[0] - '0') ans++;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) ans++;
        }
        cout << ans << "\n";
    }
}