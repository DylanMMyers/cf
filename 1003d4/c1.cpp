#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c1.exe

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
        cin >> b[0];
        if (b[0] - a[0] < a[0]) a[0] = b[0] - a[0];
        for (int i = 1; i < n - 1; i++) {
            if (b[0] - a[i] < a[i] && b[0] - a[i] >= a[i - 1]) a[i] = b[0] - a[i];
        }
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) flag = true;
        }
        cout << (flag == true ? "NO\n" : "YES\n");
    }
}