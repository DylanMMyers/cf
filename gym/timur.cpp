#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        string cf = "codeforces";
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i] != cf[i]) ans++; 
        }
        cout << ans << "\n";
    }
}