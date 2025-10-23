#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c2.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        a[0] = min(a[0], b[0] - a[0]);
        bool flag = false;
        for (int i = 1; i < n; i++) {
            int low = 0, high = m - 1;
            while (low < high) {
                int mid = (low + high) / 2;
                if (b[mid] - a[i] >= a[i - 1]) high = mid;
                else low = mid + 1;
            }
            if (min(a[i], b[low] - a[i]) >= a[i - 1]) a[i] = min(a[i], b[low] - a[i]);
            else if (max(a[i], b[low] - a[i]) >= a[i - 1]) a[i] = max(a[i], b[low] - a[i]);
            else {
                flag = true;
                break;
            }
        }
        cout << (flag == true ? "NO\n" : "YES\n");
    }
}