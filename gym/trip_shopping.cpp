#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\trip_shopping.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) if (b[i] < a[i]) swap(a[i], b[i]);
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += b[i] - a[i];
        // now we need to find what we will change
        vector<pair<int,int>> res;
        for (int i = 0; i < n; i++) res.push_back({a[i], b[i]});
        sort(res.begin(), res.end());
        bool found = false;
        for (int i = 1; i < n; i++) {
            if (res[i].first <= res[i - 1].second) {
                cout << ans << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            int mini =  2e9;
            for (int i = 1; i < n; i++) {
                mini = min(mini, res[i].first - res[i - 1].second);
            }
            cout << ans + 2*mini << "\n";
        }
    }
}