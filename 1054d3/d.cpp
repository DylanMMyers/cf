#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            a += (s[i] == 'a');
            b += (s[i] == 'b');
        }
        int ac = 0, bc = 0;
        ll ascore = 0, bscore = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                ascore += min(i - ac, n - (a - ac) - i);
                ac++;
            }
            else {
                bscore += min(i - bc, n - (b - bc) - i);
                bc++;
            }
        }
        cout << min(ascore, bscore) << "\n";
    }
}
