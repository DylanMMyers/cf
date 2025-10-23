#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == y && y == z) {
            cout << "YES\n";
            continue;
        }
        vector<int> v = {x, y, z};
        bool ans = true;
        for (int i = 0; i < 30; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                if ((1 << i) & v[j]) sum++;
            }
            if (sum == 2) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}