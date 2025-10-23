#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        if (n == 1 || n == 2) {
            cout << "YES\n";
            continue;
        }
        bool ans = true, curr = (s[0] == '1');
        int c = 0;
        for (int i = 0; i < n; i++) {
            c += (s[i] == '0');
            if (!i) continue;
            if (s[i] == '0' && s[i - 1] == '0') curr = false;
            if (s[i] == '1' && s[i - 1] == '1') {
                if (curr && c % 2 == 1) {
                    ans = false;
                    break;
                }
                curr = true;
                c = 0;
            }
        }
        if (curr && c % 2 == 1 && s[n - 1] == '1') ans = false;
        cout << (ans ? "YES\n" : "NO\n");
    }
}

// i wave white flag ;-;