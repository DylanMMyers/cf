#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        if (n == 1) {
            cout << "YES\n1\n";
            continue;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int curr = v[i][0];
            if (!i) curr = v[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (!i && !j) continue;
                curr &= v[i][j];
            }
            ans[i] = curr;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if ((ans[i] | ans[j]) != v[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " \n"[i == n - 1];
            }
        }
    }
}