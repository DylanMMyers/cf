#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int x;
        cin >> x;
        int zeros = 32 - __builtin_clz(x);
        bool f = true;
        int z = 0;
        for (int i = zeros - 1; i >= 0; i--) {
            if (!f) break;
            z = (1 << i - 1);
            int c;
            for (int j = i - 1; j >= 0; j--) {
                z += (1 << j);
                c = x ^ z;
                if ((c > 1) && (x + c > z) && (x + z > c) && (c + z > x) && (z < x)) {
                    f = false;
                    break;
                }
                z -= (1 << j);
            }
        }
        if (f) cout << "-1\n";
        else cout << z << "\n";
    }
}