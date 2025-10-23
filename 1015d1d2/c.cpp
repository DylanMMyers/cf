#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        unordered_map<int, int> mpa, mpb;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mpa[a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        reverse(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            mpb[b[i]] = i;
        }
        vector<pair<int, int>> res;
        int curr = 0;
        for (int i = 0; i < (n / 2) + 1; i++) {
            if (curr == n + 1) break;
            else if (a[i] != b[i]) {
                int x = i, y = mpa[b[i]];
                swap(a[x], a[y]);
                mpa[a[x]] = x;
                mpa[a[y]] = y;
                swap(b[n - x - 1], b[n - y - 1]);
                mpb[b[n - x - 1]] = n - x - 1;
                mpb[b[n - y - 1]] = n - y - 1;
                res.push_back({x, y});
                i--;
                curr++;
            }
            else curr = 0;
        }
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                f = false;
                break;
            }
        }
        if (!f) cout << "-1\n";
        else {
            cout << res.size() << "\n";
            for (auto x : res) {
                cout << x.first + 1 << ' ' << x.second + 1 << "\n";
            }
        }
    }
}