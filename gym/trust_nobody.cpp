#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\trust_nobody.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        bool f = false;
        for (int i = 1; i < n; i++) {
            if (v[i] != v[i - 1]) {
                f = true;
                break;
            }
        }
        if (f) {
            int ans = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (v[i] == n) ans++;
                else break;
            }
            cout << ans << "\n";
        }
        else {
            if (v[0] == 0) cout << "0\n";
            else if (v[0] == n) cout << "-1\n";
            else cout << v[0] << "\n";
        }
    }
}