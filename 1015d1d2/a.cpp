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
        int n;
        cin >> n;
        if (n % 2 == 0) cout << "-1\n";
        else {
            cout << n;
            for (int i = 1; i < n; i++) {
                cout << ' ' << i;
            }
            cout << "\n";
        }
    }
}