#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\mexdestruction.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int z = 0, o = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) z++;
        }
        int it = 0, groups = 0;
        while (it < n) {
            if (v[it] == 0) {
                while (v[it] == 0 && it < n) {
                    it++;
                }
                groups++;
            }
            else it++;
        }
        if (z == n) cout << "0\n";
        else if (z == 0) cout << "1\n";
        else if ((groups == 1 && v[0] == 0) || (groups == 1 && v[n - 1] == 0)) cout << "1\n";
        else if (groups == 2 && (v[0] == 0 && v[n - 1] == 0)) cout << "1\n";
        else cout << "2\n";
    }
}