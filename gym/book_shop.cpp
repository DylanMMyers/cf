#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\book_shop.exe

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j >= price[i]) {
                dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
            }
        }
    }

    cout << dp[x] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
}