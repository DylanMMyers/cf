#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\manhattan_pairs.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> x(n), y(n);
        vector<pair<int,int>> res;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];            
            res.push_back({x[i] + y[i], i});
        }
        sort(res.begin(), res.end());
        int l = 0, r = n - 1;
        for (int i = 0; i < n / 2; i++) {
            cout << res[l].second + 1 << ' ' << res[r].second + 1 << "\n";
            l++;
            r--;
        }
    }
}