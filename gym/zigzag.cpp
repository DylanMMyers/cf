#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\zigzag.exe

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
        int maxi = v[0], ans = 0;
        for (int i = 1; i < n; i++) {
            maxi = max(v[i], maxi);
            if (i % 2) { // >
                v[i] = maxi;
                if (v[i] <= v[i - 1]) {
                    ans += v[i - 1] - v[i] + 1;
                    v[i - 1] = v[i] - 1;
                }
            }
            else if (v[i] >= v[i - 1]) { // <
                ans += v[i] - v[i - 1] + 1;
                v[i] = v[i] - v[i - 1] - 1;
            }
        }
        cout << ans << "\n";
    }
}