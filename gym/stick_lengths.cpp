#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\stick_lengths.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<ll> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + v[i - 1];
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        ll left = v[i - 1] * (i - 1) - ps[i - 1];
        ll right = (ps[n] - ps[i]) - (v[i - 1] * (n - i));
        ans = min(ans, left + right);
    }
    cout << ans;
}