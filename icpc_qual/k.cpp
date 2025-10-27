#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./k.exe
// g++ k.cpp -o k
using namespace std;

int main() {
    bool ok = false;
    vector<pair<int,int>> v = {{2, 4}, {4, 4}, {4, 2}};
    for (int i = 0; i < 3; i++) {
        cout << "? " << v[i].first << ' ' << v[i].second << "\n";
        cin >> ok;
        if (!ok) continue;
        bool ok2;
        cout << "? " << v[i].first << ' ' << v[i].second - 1 << "\n";
        cin >> ok2;
        if (ok2) {
            bool ok3;
            cout << "? " << v[i].first + 1 << ' ' << v[i].second - 1 << "\n";
            cin >> ok3;
            if (ok3) {
                cout << "! " << v[i].first << ' ' << v[i].second - 1 << "\n";
                return 0;
            }
            else {
                cout << "! " << v[i].first - 1 << ' ' << v[i].second - 1 << "\n";
                return 0;
            }
        }
        else {
            cout << "? " << v[i].first + 1 << ' ' << v[i].second + 1 << "\n";
            bool ok4;
            cin >> ok4;
            if (ok4) {
                cout << "! " << v[i].first << ' ' << v[i].second << "\n";
                return 0;
            }
            else {
                cout << "! " << v[i].first - 1 << ' ' << v[i].second << "\n";
                return 0;
            }

        }
    }
    bool ok5, ok6;
    cout << "? 2 3\n";
    cin >> ok5;
    cout << "? 3 2\n";
    cin >> ok6;
    if (ok5 && ok6) cout << "! 2 2\n";
    else if (ok5) cout << "! 1 2\n";
    else if (ok6) cout << "! 2 1\n";
    else cout << "! 1 1\n";
}