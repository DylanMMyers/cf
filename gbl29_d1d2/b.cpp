#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "1 1\n";
            continue;
        }
        if (n == 2) {
            cout << "1 2 1 2\n";
            continue;
        }
        vector<int> ans(2 * n);
        // 6 4 2 5 2 4 6 3 5 1 3 1
        // 7 5 3 1 6 3 5 7 4 2 6 2 4 1
        // 5 3 1 4 3 5 2 4 2 1
        int place, idx;
        if (n % 2) { // odd
            place = n, idx = 0;
            while (place > 1) {
                ans[idx] = place;
                ans[idx + place] = place;
                place -= 2;
                idx++;
            }
            ans[idx] = 1;
            ans[idx + 1] = n - 1;
            ans[idx + n] = n - 1;
            ans.back() = 1;
            place = n - 3;
            idx = n + 1;
            while (place > 0) {
                ans[idx] = place;
                ans[idx + place] = place;
                place -= 2;
                idx++;
            }
        }
        else { // even
            place = n, idx = 0;
            while (place > 1) {
                ans[idx] = place;
                ans[idx + place] = place;
                place -= 2;
                idx++;
            }
            ans[idx] = n - 1;
            ans[idx + n - 1] = n - 1;
            idx = n + 1;
            place = n - 3;
            while (place > 1) {
                if (ans[idx]) {
                    idx++;
                    continue;
                }
                ans[idx] = place;
                ans[idx + place] = place;
                idx++;
                place -= 2;
            }
            for (int i = 0; i < 2 * n; i++) {
                if (!ans[i]) ans[i] = 1;
            }
        }
        for (int i = 0; i < 2 * n; i++) {
            cout << ans[i] << " \n"[i == (2 * n - 1)];
        }
    }
}