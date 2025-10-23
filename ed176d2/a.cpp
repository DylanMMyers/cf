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
        int n, k;
        cin >> n >> k;
        int ans = 0;
        if (n % 2 == 0) {
            ans += n / (k - 1);
            n = n % (k - 1);
        }
        else {
            ans++;
            n -= k;
            ans += n / (k - 1);
            n = n % (k - 1);
        }
        if (n == 0) cout << ans << "\n";
        else cout << ans + 1 << "\n";
    }
}