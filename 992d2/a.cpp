#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        flag = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if ((v[i] - v[j]) % k == 0 || (v[j] - v[i]) % k == 0) flag = false;
        }
        if (flag) {
            cout << "YES\n" << i + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
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