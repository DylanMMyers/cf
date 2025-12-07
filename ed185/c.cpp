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
        ll n, k; cin >> n >> k;
        vector<ll> q(n), r(n);
        for (int i = 0; i < n; i++) cin >> q[i];
        for (int i = 0; i < n; i++) cin >> r[i];
        sort(q.begin(), q.end());
        sort(r.begin(), r.end());
        int rit = n - 1, ops = 0;
        for (int i = 0; i < n; i++) {
            while (rit > -1 && (q[i] + 1) * (r[rit] + 1) - 1 > k) {
                rit--;
            }
            if (rit == -1) break;
            ops++;
            rit--;
        }
        cout << ops << "\n";
    }
}