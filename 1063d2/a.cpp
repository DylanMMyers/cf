#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe
// g++ a.cpp -o a

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
        sort(v.begin(), v.end());
        bool turn = true;
        for (int i = 0; i < n - 1; i++) {
            if (turn && v[i] > v[i + 1]) swap(v[i], v[i + 1]);
            else if (!turn && v[i] < v[i + 1]) swap(v[i], v[i + 1]);
            turn = !(turn);
        }
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (v[i] < v[i - 1]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}