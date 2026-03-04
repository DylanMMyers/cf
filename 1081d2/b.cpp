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
        vector<int> v(n), ops;
        for (int i = 0; i < n; i++) {
            char x; cin >> x;
            v[i] = x - '0';
        }
        int o = 0, z = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) z++;
            else o++;
        }
        if (o == 0) {
            cout << "0\n";
            continue;
        }

        bool ok = false;
        if (o % 2 == 0) {
            for (int i = 0; i < n; i++) {
                if (v[i] == 1) ops.push_back(i);
            }
            ok = true;
        }
        else if (z % 2 == 1) {
            for (int i = 0; i < n; i++) {
                if (v[i] == 0) ops.push_back(i);
            }
            ok = true;
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }
        cout << ops.size() << '\n';
        for (int i = 0; i < ops.size(); i++) cout << ops[i] + 1 << " \n"[i == ops.size() - 1];
    }
}

// 101010
// 110101
// 