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
        int ans = 0;
        for (int i = 1; i <= n * n; i++) {
            int x = i;
            if (i - n >= 1) x += i - n;
            if (i + n <= n * n) x += i + n;
            if ((i - 1) % n) x += i - 1;
            if (i % n) x += i + 1;
            ans = max(ans, x); 
        }
        cout << ans << "\n";
    }
}