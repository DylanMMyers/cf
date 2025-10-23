#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\same.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        bool ans = true;
        for (int i = 1; i < n; i++) {
            int y;
            cin >> y;
            if (x != y) ans = false;
        }
        cout << (ans ? "Yes" : "No");
    }
}