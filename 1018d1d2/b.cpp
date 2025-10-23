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
        int n, k;
        cin >> n >> k;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }
        // first, add the max of array l_i or r_i to the sum
        // next, we sort the arrays and add k - 1 max values to ans, then + 1
        ll ans = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            if (l[i] > r[i]) {
                ans += l[i];
                l[i] = -1;
                pq.push(r[i]);
            }
            else {
                ans += r[i];
                r[i] = -1;
                pq.push(l[i]);
            }
        }
        while (k > 1) {
            ans += pq.top();
            pq.pop();
            k--;
        }
        cout << ans + 1 << "\n";
    }
}