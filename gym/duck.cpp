#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\duck.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int x, y, z;
        cin >> x >> y >> z;
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a >= x) {
            a -= x;
        }
        else {
            cout << "NO";
            break;
        }

        if (a >= y) a -= y;
        else if (b >= y) b -= y;
        else if ((a + b) >= y) {
            y -= a;
            a = 0;
            b -= y;
        }
        else {
            cout << "NO";
            break;
        }

        if ((a + b + c) >= z) cout << "YES";
        else cout << "NO";
    }
}