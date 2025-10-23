#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\dora_and_cpp.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int g = __gcd(a, b);
        for (int i = 0; i < n; i++) {
            v[i] %= g;
        }
        sort(v.begin(), v.end());
        int ans = v[n - 1] - v[0];
        for (int i = 1; i < n; i++) {
            ans = min(ans, v[i - 1] + g - v[i]);
        }
        cout << ans << "\n";
    }
}