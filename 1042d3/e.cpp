#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\e.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), ares(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ares[i] = a[i];
        }
        for (int i = 0; i < n; i++) cin >> b[i];
        if (a.back() != b.back()) {
            cout << "NO\n";
            continue;
        }
        bool res = true;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] != b[i]) {
                if ((a[i] ^ a[i + 1]) == b[i]) ares[i] = a[i] ^ a[i + 1];
                else if ((a[i] ^ ares[i + 1]) == b[i]) ares[i] = a[i] ^ ares[i + 1];
                else {
                    res = false;
                    break;
                }
            }
        }
        cout << (res ? "YES\n" : "NO\n");
    }
}