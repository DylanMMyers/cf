#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\restaurant_customers.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0, curr = 0, l = 0, r = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (l == n || r == n) break;

        if (a[l] < b[r]) {
            curr++;
            l++;
        }
        else {
            curr--;
            r++;
        }
        ans = max(ans, curr);
    }
    cout << ans;
}