#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int k, a, b;
        cin >> k >> a >> b;
        bool ans = false;
        for (int i = a; i <= b; i++) {
            if (i % k == 0) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "OK" : "NG");
    }
}