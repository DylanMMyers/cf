#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        // we will send everyone to n or n - 1 depending on parity of k
        // for n and n - 1 they will point towards each other by default (handle seperately) or do they point to an earlier node for k >= 2? (figure out later)
        int n, k;
        cin >> n >> k;
        int dest = !(k % 2);
        for (int i = 1; i <= n - 2; i++) {
            cout << n - dest << ' ';
        }
        cout << n << ' ' << n - 1 << "\n";
    }
}