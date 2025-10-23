#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        if (n == 1) {
            cout << k << "\n";
            continue;
        }
        int a = 1;
        while (((a * 2) - 1) <= k) {
            a *= 2;
        }
        a--;
        cout << a << ' ' << k - a << ' ';
        if (n == 2) cout << "\n";
        for (int i = 2; i < n; i++) {
            cout << 0 << " \n"[i == n - 1];
        }
    }
}