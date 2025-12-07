#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(2 * n), c(2 * n + 1, 0);
        int o = 0, m4 = 0, dc = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> v[i];
            c[v[i]]++;
        }
        for (int i = 1; i < 2 * n + 1; i++) {
            if (c[i]) dc++;
            if (c[i] % 2) o++;
            if ((c[i] % 4) == 0 && c[i]) m4++;
        }
        cout << o + 2 * (dc - o - m4) + (m4 - (m4 % 2)) << "\n";
    }
}