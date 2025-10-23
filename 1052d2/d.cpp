#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int l, r; cin >> l >> r;
        ll score = 0;
        vector<int> p(r + 1, -1);
        for (int i = i; i <= r; i++) {
            int x = 0, bit = 0;
            while (x <= r) {
                if (!(1 << bit & i)) {
                    if (x + (1 << bit) > r) break; 
                    x += 1 << bit;
                }
                bit++;
            }
            p[i] = x;
            score += x + i;
        }
        cout << score << "\n";
        for (int i = 0; i <= r; i++) {
            cout << p[i] << " \n"[i == r];
        }
    }
}

// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000
// 1001