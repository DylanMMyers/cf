#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

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
        if (v[0] == 1) {
            cout << v[0] << ' ' << v[1] << "\n";
            continue;
        }
        bool f = false;
        for (int i = 0; i < min(100, n); i++) {
            for (int j = i + 1; j < n; j++) {
                if (!((v[j] % v[i]) % 2)) {
                    cout << v[i] << ' ' << v[j] << "\n";
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        if (f) continue;
        for (int i = n - 1; i >= max(n - 100, 0); i--) {
            for (int j = 0; j < i; j++) {
                if (!((v[i] % v[j]) % 2)) {
                    cout << v[i] << ' ' << v[j] << "\n";
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        if (!f) cout << "-1\n";
    }
}