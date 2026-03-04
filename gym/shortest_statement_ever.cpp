#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\shortest_statement_ever.exe
// g++ shortest_statement_ever.cpp -o shortest_statement_ever

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int x, y; cin >> x >> y;
        int p = 0, q = 0;
        for (int i = 0; i < 32; i++) {
            int setx = (1 << i) & x, sety = (1 << i) & y;
            if (setx) {
                p += (1 << i);
            }
            else if (sety) {
                q += (1 << i);
            }
        }
        cout << p << ' ' << q << '\n';
    }
}

// 0111
// 1011

// 0011
// 1001