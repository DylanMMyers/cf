#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // make alternating sum of negative, positive with the highest magnitudes
    ll sum = accumulate(v.begin(), v.end(), 0);
    while (n > 1) {
        vector<ll> diff, reverse_diff;
        for (int i = 1; i < n; i++) {
            diff.push_back(v[i] - v[i - 1]);
        }
        reverse(v.begin(), v.end());
        for (int i = 1; i < n; i++) {
            reverse_diff.push_back(v[i] - v[i - 1]);
        }
        ll dsum = accumulate(diff.begin(), diff.end(), 0ll), rdsum = accumulate(reverse_diff.begin(), reverse_diff.end(), 0ll);
        if (dsum >= rdsum) v = diff;
        else v = reverse_diff;
        sum = max({sum, dsum, rdsum});
        n--;
    }
    cout << max(sum, v[0]) << "\n";
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