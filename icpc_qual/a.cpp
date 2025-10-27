#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./a.exe
// g++ a.cpp -o a
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, g, b; cin >> r >> g >> b;
    int ownr, owng, ownb; cin >> ownr >> owng >> ownb;
    int x, y; cin >> x >> y;
    int ans = 0;
    if (ownr < r) {
        if (r - ownr > x) {
            cout << -1;
            return 0;
        }
        x -= r - ownr;
        ans += r - ownr;
        ownr = r;
    }
    if (ownb < b) {
        if (b - ownb > y) {
            cout << -1;
            return 0;
        }
        y -= b - ownb;
        ans += b - ownb;
        ownb = b;
    }
    if (owng < g) {
        int xy = x + y;
        if (g - owng > xy) {
            cout << -1;
            return 0;
        }
        ans += g - owng;
    }
    cout << ans;
}