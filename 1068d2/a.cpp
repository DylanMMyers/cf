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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int ans = 0, wait = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                wait = k;
                continue;
            }
            if (wait > 0) {
                wait--;
                continue;
            }
            else ans++;
        }
        cout << ans << "\n";
    }
}