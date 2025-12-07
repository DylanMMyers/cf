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
        int diff = 0;
        for (int i = 1; i < n - 1; i++) {
            if (v[i] == -1) {
                v[i] = 0;
            }
        }
        if (v[0] == -1 && v[n - 1] == -1) {
            v[0] = 0;
            v[n - 1] = 0;
        }
        else if (v[0] == -1) {
            v[0] = v[n - 1];
        }
        else if (v[n - 1] == -1) {
            v[n - 1] = v[0];
        }
        cout << abs(v[n - 1] - v[0]) << "\n";
        for (int i = 0; i < n; i++) {
            cout << v[i] << " \n"[i == n - 1];
        }
    }
}