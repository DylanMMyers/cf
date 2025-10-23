#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        string tr;
        for (int i = 0; i < n; i++) {
            cin >> tr >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = 10e7;
        for (int i = 1; i < n; i++) {
            ans = min(ans, v[i] - v[i - 1]);
        }
        cout << ans << "\n";;
    }
}