#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<ll> copy = v;
        sort(copy.begin(), copy.end());
        vector<ll> ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + copy[i - 1];
        }
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = 1 + (high + low) / 2;
            if (copy[mid] * mid - ps[mid] <= k) low = mid;
            else high = mid - 1;
        }
        for (int i = 0; i < n; i++) {
            if (v[i] < copy[low]) {
                k -= (copy[low] - v[i]);
                v[i] = copy[low];
            }
        }
        if (k > 0) {
            int c = k / (low + 1);
            k -= k / (low + 1);
            for (int i = 0; i < n; i++) {
                if (v[i] == copy[low]) v[i] += c;
            }
            int it = n - 1;
            while (k > 0) {
                v[it]++;
                k--;
                it--;
            }
        }
        ll mini = *min_element(v.begin(), v.end());
        ll ans = (mini * n) - n + 1;
        for (int i = 0; i < n; i++) {
            v[i] -= mini;
        }
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                ans++;
                v[i]--;
            }
            else break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] > 0) {
                ans++;
                v[i]--;
            }
            else break;
        }
        cout << ans << "\n";
    }
}