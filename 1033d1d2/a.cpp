#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        bool w = ((l1 == l2) && (l1 == l3) && (l2 == l3)), h = ((b1 == b2) && (b1 == b3) && (b2 == b3));
        if ((l1 + l2 + l3 == b1) && h) cout << "YES\n";
        else if ((b1 + b2 + b3 == l1) && w) cout << "YES\n";
        else if ((b2 == b1) && (l3 == l1 + l2) && (b1 + b3 == l1 + l2)) cout << "YES\n"; // 3 top left, 1 bottom left, 2 bottom right
        else if ((b2 == b1 + b3) && (l1 == l3) && (l1 + l2 == b1 + b3)) cout << "YES\n"; // done
        else if ((b1 == b2) && (l3 == l2 + l1) && (b2 + b3 == l2 + l1)) cout << "YES\n"; // done
        else if ((b1 == b2 + b3) && (l2 == l3) && (l2 + l1 == b2 + b3)) cout << "YES\n";
        else if ((b1 == b3) && (l2 == l3 + l1) && (b3 + b2 == l3 + l1)) cout << "YES\n"; // done
        else if ((b1 == b3 + b2) && (l3 == l2) && (l3 + l1 == b3 + b2)) cout << "YES\n"; 
        else if ((b3 == b1) && (l2 == l1 + l3) && (b1 + b2 == l1 + l3)) cout << "YES\n"; // done
        else if ((b3 == b1 + b2) && (l1 == l2) && (l1 + l3 == b1 + b2)) cout << "YES\n"; 
        else if ((b3 == b2) && (l1 == l2 + l3) && (b2 + b1 == l2 + l3)) cout << "YES\n"; // done
        else if ((b3 == b2 + b1) && (l2 == l1) && (l2 + l3 == b2 + b1)) cout << "YES\n"; 
        else if ((b2 == b3) && (l1 == l3 + l2) && (b3 + b1 == l3 + l2)) cout << "YES\n"; // done
        else if ((b2 == b3 + b1) && (l3 == l1) && (l3 + l2 == b3 + b1)) cout << "YES\n"; 
        else cout << "NO\n";
    }
}