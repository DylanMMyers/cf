#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // where to start the second group
    if (k == n) {
        for (int i = 1; i < n; i += 2) {
            if (v[i] != (1 + (i / 2))) {
                cout << (1 + (i / 2)) << "\n";
                return;
            }
        }
        cout << (n / 2) + 1 << "\n";
        return;
    }
    int oc = 0;
    for (int i = 1; i < n - k + 2; i++) {
        if (v[i] == 1) oc++;
    }
    if (oc == n - k + 1) cout << "2\n";
    else cout << "1\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}