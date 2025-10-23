#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\skibidi_table.exe

pair<int,int> findxy(int d, int lx, int ly, int rx, int ry) {
    a
}

int findd() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        n = pow(2, n);
        int q; cin >> q;
        for (int i = 0; i < q; i++) {
            string s; cin >> s;
            if (s == "->") {
                int x, y; cin >> x >> y;
                // pass a, b, c, d recursively
                cout << findd(x, y, 1, ) << "\n";
            }
            else {
                int d; cin >> d;
                // pass (l1, l2) (r1, r2) recursively
                pair<int,int> c = findxy(d, 1, 1, n, n);
                cout << c.first << ' ' << c.second << "\n";
            }
        }
    }
}