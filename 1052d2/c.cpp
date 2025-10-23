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
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') p[i] = i + 1;
        }
        int l = 0, it = 0;
        while (l < n && s[l] == '1') {
            l++;
        }
        bool ans = true;
        for (int i = l; i < n; i++) {
            if (s[i] == '0') continue;
            
            if (i - l == 1) {
                ans = false;
                break;
            }

            it = 0;
            for (int j = l; j < i; j++) {
                p[j] = i - it;
                it++;
            }

            l = i;
            while (l < n && s[l] == '1') {
                l++;
            }
        }

        if (n - l == 1) ans = false;
        
        if (!ans) {
            cout << "NO\n";
            continue;
        }

        if (l < n) {
            it = n;
            for (int i = l; i < n; i++) {
                p[i] = it;
                it--;
            }
        }
        
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n - 1];
    }
}