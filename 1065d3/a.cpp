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
        if (n % 2) {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; i <= n; i += 2) {
            if (((n - i) % 4) == 0) ans++;
        }
        cout << ans << "\n";
    }
}