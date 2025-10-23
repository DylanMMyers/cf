#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

// can always use all counts of even sides, then up to 2 other sides
// check edge case for if side count = 2, ans is always 0 in this case
// otherwise greedily take all even side counts and find the other 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<ll> sides;
        ll ans = 0;
        ll freq = 1, curr = v[0], sc = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] != v[i - 1]) {
                if (freq % 2) {
                    sides.push_back(curr);
                    ans += curr * (freq - 1);
                    sc += freq - 1;
                }
                else {
                    ans += curr * freq;
                    sc += freq;
                }
                curr = v[i];
                freq = 0;
            }
            freq++;
        }
        if (freq % 2) {
            sides.push_back(curr);
            ans += curr * (freq - 1);
            sc += freq - 1;
        }
        else {
            ans += freq * curr;
            sc += freq;
        }
        if (sides.size() > 0) {
            bool found = false;
            for (int i = sides.size() - 1; i > 0; i--) {
                if (sides[i] + ans > sides[i - 1] && sides[i - 1] + ans > sides[i]) {
                    ans += sides[i] + sides[i - 1];
                    sc += 2;
                    found = true;
                    break;
                }
            }
            if (!found) {
                int curr2 = -1;
                for (int i = 0; i < sides.size(); i++) {
                    if (sides[i] < ans) curr2 = i;
                }
                if (curr2 != -1) {
                    ans += sides[curr2];
                    sc++;
                }
            }
        }
        if (sc == 2) ans = 0;
        cout << ans << "\n";
    }
}