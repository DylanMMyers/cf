#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe
// g++ c.cpp -o c

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<int> v(n);
        ll score = 0;
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> res;
        int l = 0, r = n - 1, sum = 0;
        while (l <= r) {
            if (sum + v[l] < x) {
                sum += v[l];
                res.push_back(v[l]);
                l++;
            }
            else {
                sum += v[r];
                sum %= x;
                score += v[r];
                res.push_back(v[r]);
                r--;
            }
        }
        cout << score << "\n";
        for (int i = 0; i < n; i++) {
            cout << res[i] << " \n"[i == n - 1];
        }
    }
}