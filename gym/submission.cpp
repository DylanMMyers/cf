#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\submission.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ans += (v[i] == 0 ? 1 : v[i]);
        }
        cout << ans << "\n";
    }
}