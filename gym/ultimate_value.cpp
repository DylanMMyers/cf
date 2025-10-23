#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\ultimate_value.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n + 1);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            sum += v[i] * (i % 2 ? 1 : -1);
        }
        if (n == 1) {
            cout << sum << "\n";
            continue;
        }
        ll maxi = 0;
        priority_queue<int> pqe, pqo; // pqe is what we would gain if we swap an odd with max even and vice versa
        if (n % 2) pqo.push(-2 * v[n] + n);
        else pqe.push(2 * v[n] + n);
        for (int i = n - 1; i > 0; i--) {
            if (i % 2) { // odd idx
                maxi = max(maxi, (ll)(-2 * v[i] - i + pqe.top()));
                pqo.push(-2 * v[i] + i);
            }
            else { // even idx
                maxi = max(maxi, (ll)(2 * v[i] - i + pqo.top()));
                pqe.push(2 * v[i] + i);
            }
        }
        cout << sum + max(maxi, (ll)(n % 2 ? n - 1 : n - 2)) << "\n";
    }
}