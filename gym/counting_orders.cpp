#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\counting_orders.exe

int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        // 6 5 6 3 4 2
        // 5 4 5 2 3 1
        ll ans = 1;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            int low = 0, high = n - 1;
            while (low < high) {
                int mid = 1 + (low + high) / 2;
                if (a[mid] > b[i]) low = mid;
                else high = mid - 1;
            }
            if (a[low] > b[i]) ans = (ans * (low + 1)) % MOD;
            else ans = 0;
        }
        cout << ans << "\n";
    }
}