#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\exponentiation.exe
// g++ exponentiation.cpp -o exponentiation

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int MOD = 1e9 + 7;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        if (a == 0 && b == 0) {
            cout << "1\n";
            continue;
        }
        a %= MOD;  // note: m * m must be less than 2^63 to avoid ll overflow
        ll res = 1;
        while (b > 0) {
            if (b % 2 == 1) res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        cout << res << '\n';
    }
}