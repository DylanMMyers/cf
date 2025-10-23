#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\sums_on_segments.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, x = 1;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] != -1 && v[i] != 1) x = v[i];
        }
        // have running max count
        // have running min count
        // when we find x, reset and skip over it
        // essentially find all subarray sums around our x value this way
        // then, we do one more sweep around our x value given we have one (x != 1 in this case)
        // then, for these two running maxes we know that all values in between are possible by using slight brainpower
        ll maxi = 0, runmaxi = 0, mini = 0, runmini = 0, xidx = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] == x && x != 1) {
                runmaxi = 0, runmini = 0, xidx = i;
                continue;
            }

            runmaxi += v[i];
            runmini += v[i];
            maxi = max(maxi, runmaxi);
            mini = min(mini, runmini);
            runmini = min(runmini, 0ll);
            runmaxi = max(runmaxi, 0ll);
        }
        set<ll> ans = {0};
        for (int i = mini; i <= maxi; i++) {
            ans.insert(i);
        }
        if (xidx > -1) {
            ans.insert(x);
            ll maxil = 0, runmaxil = 0, minil = 0, runminil = 0;
            for (int i = xidx - 1; i >= 0; i--) {
                runmaxil += v[i];
                runminil += v[i];
                maxil = max(maxil, runmaxil);
                minil = min(minil, runminil);
            }
            runmaxil = maxil, runminil = minil;
            for (int i = xidx + 1; i < n; i++) {
                runmaxil += v[i];
                runminil += v[i];
                maxil = max(maxil, runmaxil);
                minil = min(minil, runminil);
            }
            for (int i = x + minil; i <= x + maxil; i++) {
                ans.insert(i);
            }
        }
        cout << ans.size() << "\n";
        for (auto ele : ans) {
            cout << ele << ' ';
        }
        cout << "\n";
    }
}