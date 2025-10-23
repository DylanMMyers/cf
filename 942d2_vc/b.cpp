#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int u = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') u++;
        }
        cout << (u % 2 == 1 ? "YES\n" : "NO\n");
    }
}