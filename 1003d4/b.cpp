#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cout << "1\n";
            return;
        }
    }
    cout << n << "\n";
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