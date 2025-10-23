#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\come_together.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int x, y, bx, by, ax, ay;
        cin >> x >> y >> bx >> by >> ax >> ay;
        int maxix = 0, maxiy = 0;
        if (x > bx && x > ax) maxix = min(x - bx, x - ax);
        else if (x < bx && x < ax) maxix = min(bx - x, ax - x);
        if (y > by && y > ay) maxiy = min(y - by, y - ay);
        else if (y < by && y < ay) maxiy = min(by - y, ay - y);
        cout << maxix + maxiy + 1 << "\n";
    }
}