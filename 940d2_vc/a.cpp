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
        int n; cin >> n;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int c = 1, ans = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] == v[i - 1]) c++;
            else {
                ans += c / 3;
                c = 1;
            }
        }
        ans += c / 3;
        cout << ans << "\n";
    }
}