#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\wizards.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        vector<int> f(n), pref(n + 1, 0), suf(n + 1, 0);
        bool ok = true;
        f[0] = 0; // 0 left, 1 right
        for (int i = 1; i < n; i++) {
            int dif = v[i] - v[i - 1];
            if (dif == -1) {
                // prev must face right, curr must face right
                f[i] = 1;
                if (f[i - 1] == 0) {
                    ok = false;
                    break;
                }
            }
            else if (dif == 0) {
                // prev must face right and curr must face left
                // or
                // prev must face left and curr must face right
                // so we will base it off of where prev faced
                if (f[i - 1] == 0) f[i] = 1;
                else f[i] = 0;
            }
            else if (dif == 1) {
                // prev must face left, curr must face right
                f[i] = 0;
                if (f[i - 1] == 1) {
                    ok = false;
                    break;
                }
            }
            else {
                ok = false;
                break;
            }
        }
        if (ok) {
            suf[n] = (f[n - 1] == 1);
            for (int i = n - 1; i > 0; i--) {
                suf[i] = f[i - 1] + suf[i + 1];
            }
            for (int i = 1; i <= n; i++) {
                pref[i] = (1 - f[i - 1]) + pref[i - 1];
            }
            for (int i = 1; i <= n; i++) {
                if ((pref[i] - (f[i - 1] == 0)) + (suf[i] - (f[i - 1] == 1)) + 1 != v[i - 1]) {
                    ok = false;
                    break;
                }
            }
            ans += (int)ok;
        }
        f[0] = 1;
        ok = true;
        for (int i = 1; i < n; i++) {
            int dif = v[i] - v[i - 1];
            if (dif == -1) {
                // prev must face right, curr must face right
                f[i] = 1;
                if (f[i - 1] == 0) {
                    ok = false;
                    break;
                }
            }
            else if (dif == 0) {
                // prev must face right and curr must face left
                // or
                // prev must face left and curr must face right
                // so we will base it off of where prev faced
                if (f[i - 1] == 0) f[i] = 1;
                else f[i] = 0;
            }
            else if (dif == 1) {
                // prev must face left, curr must face right
                f[i] = 0;
                if (f[i - 1] == 1) {
                    ok = false;
                    break;
                }
            }
            else {
                ok = false;
                break;
            }
        }
        if (ok) {
            suf[n] = (f[n - 1] == 1);
            for (int i = n - 1; i > 0; i--) {
                suf[i] = f[i - 1] + suf[i + 1];
            }
            for (int i = 1; i <= n; i++) {
                pref[i] = (1 - f[i - 1]) + pref[i - 1];
            }
            for (int i = 1; i <= n; i++) {
                if ((pref[i] - (f[i - 1] == 0)) + (suf[i] - (f[i - 1] == 1)) + 1 != v[i - 1]) {
                    ok = false;
                    break;
                }
            }
            ans += (int)ok;
        }
        cout << ans << "\n";
    }
}