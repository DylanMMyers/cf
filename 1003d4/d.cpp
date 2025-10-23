#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n, vector<ll>(m));
        vector<ll> sum(m, 0);
        priority_queue<ll> pq;
        ll curr = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                curr += v[i][j];
                sum[j] += v[i][j];
            }
            pq.push(curr);
            curr = 0;
        }
        for (int i = 1; i < m; i++) {
            sum[i] += sum[i - 1];
        }
        for (int i = 0; i < m; i++) {
            ans += sum[i];
        }
        ll it = 1;
        while (!pq.empty()) {
            ans += (m * (n - it)) * pq.top();
            pq.pop();
            it++;
        }
        cout << ans << "\n";
    }
}