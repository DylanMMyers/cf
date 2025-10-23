#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\hungry_games.exe

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << (v[0] <= x ? "1\n" : "0\n");
        return;
    }
    // how many sums can we find such that the final value we add to the segment doesn't exceed x
    // initially, we can discard any number > x from being the end of a segment, otherwise just ps and we have some ans?
    // sliding window, ans += 1 for every new valid window
    // if sum of window = x, slide left it
    // if sum of window + newval > x, slide left it
    // otherwise slide right it
    // dont consider windows of len 1, lets just iterate through before and add 1 to ans for every value <= x
    // then, we also need to consider if the array has values > x, cause any segment including them and some value immediately after <= x is valid
    ll ans = 0, csum = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] <= x) ans++; // consider segments of len = 1
    }
    int segs = 0; // lol
    for (int i = 0; i < n - 1; i++) {
        csum += v[i];
        if (csum > x) { // LOOK HERE
                segs++;
                csum = 0;
                if (v[i + 1] <= x) ans += segs;
        }
    }
    int l = 0, r = 1;
    csum = v[0] + v[1];
    while (r < n) { // sliding window for all sums in between
        if (r - l < 1) { // ignore segment len = 1
            l = r;
            r++;
            if (r < n) csum = v[l] + v[r];
            continue;
        }

        if (csum > x) {
            csum -= v[l];
            l++;
        }
        else {
            r++;
            if (r < n) csum += v[r];
            ans++;
        }
    }
    cout << ans << "\n";
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