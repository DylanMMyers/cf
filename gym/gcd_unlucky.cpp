#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\gcd_unlucky.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> p(n), s(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> s[i];
        // case 1: all nums are the same
        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (p[i] == s[i]) {
                ans = true;
                for (int j = i - 1; j >= 0; j--) {
                    if (s[j] != s[i]) {
                        ans = false;
                        break;
                    }
                }
                for (int j = i + 1; j < n; j++) {
                    if (p[j] != p[i]) {
                        ans = false;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (max(p[i], s[i]) % min(p[i], s[i])) {
                ans = false;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            if (p[i - 1] < p[i] || s[i - 1] > s[i]) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}