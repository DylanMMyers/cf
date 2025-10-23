#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}