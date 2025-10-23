#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\best_price.exe

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> ev;
    for (int i = 0; i < n; ++i) {
      ev.emplace_back(a[i], 1);
      ev.emplace_back(b[i], 2);
    }
    sort(ev.begin(), ev.end());

    long long ans = 0;
    int cnt = n, bad = 0;
    for (int i = 0; i < 2 * n;) {
      auto [x, y] = ev[i];
      if (bad <= k) ans = max(ans, x * 1LL * cnt); // so essentially, the price is just the price of the highest available selling unit, and we multiply this by # of customers

      while (i < 2 * n && ev[i].first == x) {
        bad += (ev[i].second == 1); // if its a 1, its a 'buy' but still 'bad' so we add one to bad count
        bad -= (ev[i].second == 2); // if its a 2, its not a 'buy' so we remove one from bad since they're not buying anymore
        cnt -= (ev[i].second == 2); // if we reach a price where its not a 'buy', we remove it from the count since they're not buying
        ++i; // move onto next iteration
      }
    }

    // editorial crutch, had to go solve a lc easy to understand sweepline :sob:

    cout << ans << '\n';
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