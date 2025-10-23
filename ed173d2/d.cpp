#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

/*

146TH NUMBER WRONG
GG KMS

*/

void solve() {
    ll l, r, G;
    cin >> l >> r >> G;

    ll ans;
    if (l % G != 0) {
        ans = l / G;
        ans *= G;
        ans += G;
    }
    else ans = l;

    if (ans > r) {
        cout << "-1 -1\n";
        return;
    }

    if (ans + G <= r) {
        cout << ans << ' ';
        ll ansr = r - (r % G);
        while (ansr % ans == 0 && ansr > ans && ans != G) {
            ansr -= G;
        }
        cout << ansr << "\n";
        return;
    }
    
    if (ans + G > r && ans == G) {
        cout << ans << ' ' << ans << "\n";
        return;
    }
    
    cout << "-1 -1\n";
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