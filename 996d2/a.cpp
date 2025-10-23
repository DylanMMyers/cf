#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

void solve() {
    // if bob is even vs odd, if alice is even vs odd
    int n, a, b;
    cin >> n >> a >> b;

    if ((a == 1 && b == 2) || (a == n && b == n - 1)) cout << "NO";
    else if (a == b - 2 || a == b + 2) cout << "YES";
    else if (a > b && (a - b) % 2 == 0) cout << "YES";
    else if (a < b && (b - a) % 2 == 0) cout << "YES";
    else cout << "NO";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}