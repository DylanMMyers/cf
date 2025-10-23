#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c_ups.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            pq.push(v[i]);
        }
        ll c = 1, curr = pq.top(), remainder = 0;
        pq.pop();
        while (!pq.empty() && k > 0) {
            if (k / c >= pq.top() - curr) {
                k -= c * (pq.top() - curr);
                curr = pq.top();
                c++;
                pq.pop();
            }
            else {
                remainder = k - ((k / c) * c);
                curr += k / c;
                k = 0;
                break;
            }
        }
        if (k > 0) {
            remainder = k - ((k / c) * c);
            curr += k / c;
        }
        ll ans = (curr * n) - n + 1 + remainder;
        for (int i = 0; i < n; i++) {
            if (v[i] > curr) ans++;
        }
        cout << ans << "\n";
    }
}