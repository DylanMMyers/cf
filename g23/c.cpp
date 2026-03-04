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
        int n; cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        priority_queue<pair<ll, int>> pq;
        ll carry = 0, maxi = v[0];
        for (int i = 1; i < n; i++) {
            pq.push(make_pair(maxi - v[i], i));
            maxi = max(maxi, v[i]);
        }
        vector<int> ans(n);
        int it = n - 1;
        while (pq.size()) {
            ll diff = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (diff <= 0) continue;
            ans[it] = idx;
            it--;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] + 1 << " \n"[i == n - 1];
        }
    }
}