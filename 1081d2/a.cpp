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
        string s; cin >> s;
        int ans = 1;
        int maxb = 1, currb = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ans++;
                currb = 1;
            }
            else currb++;
            maxb = max(maxb, currb);
        }
        if (s.length() == 1) cout << "1\n";
        else if (maxb > 1 && s[0] != s[n - 1]) cout << ans + 1 << '\n';
        else cout << ans << '\n';
    }
}