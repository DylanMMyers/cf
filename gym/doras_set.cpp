#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\doras_set.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        int odds = 0, evens = 0;
        for (int i = a; i <= b; i++) {
            if (i % 2 == 0) evens++;
            else odds++;
        }
        int ans = 0;
        while (evens > 0 && odds > 0) {
            if (odds - 2 < 0) break;
            odds -= 2;
            evens--;
            ans++;
        }
        cout << ans << "\n";
    }
}