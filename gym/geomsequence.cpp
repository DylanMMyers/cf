#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\geomsequence.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        long double n;
        cin >> n;
        vector<long double> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long double c = v[n - 1] / v[n - 2];
        for (int i = n - 1; i > 0; i--) {
            if (v[i] / v[i - 1] != c) {
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";
    }
}