#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        string x; cin >> x;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (x[i] == '1' && (v[i] == 1 || i == 0 || v[i] == n || i == n - 1)) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        int a = find(v.begin(), v.end(), 1) - v.begin() + 1;
        int b = find(v.begin(), v.end(), n) - v.begin() + 1;
        if (a > b) swap(a, b);
        cout << "5\n";
        cout << 1 << ' ' << a << "\n";
        cout << 1 << ' ' << b << "\n";
        cout << a << ' ' << b << "\n";
        cout << a << ' ' << n << "\n";
        cout << b << ' ' << n << "\n";
    }
}