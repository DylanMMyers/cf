#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        if (k == 1) {
            bool ans = true;
            for (int i = 1; i < n; i++) {
                if (v[i] < v[i - 1]) {
                    ans = false;
                    break;
                }
            }
            cout << (ans ? "YES\n" : "NO\n");
        }
        else cout << "YES\n";
    }
}