#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                a.push_back(b[i]);
                sort(a.begin(), a.end());
                a.pop_back();
                ans++;
            }
        }
        cout << ans << "\n";
    }
}