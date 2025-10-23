#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\antenna_analysis.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, c; cin >> n >> c;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<ll> p(n);
    p[0] = 0ll;
    ll curr = -v[0] + c;
    // (xi - xj) - c(i - j)
    // (xi - xj) - c*i + c*j
    // xi - c*i - xj + c*j
    for (int i = 1; i < n; i++) {
        p[i] = max(0ll, v[i] - (c * (i + 1)) + curr);
        curr = max(curr, -v[i] + (c * (i + 1)));
    }
    // (xj - xi) - c(i - j)
    // (xj - xi) - c*i + c*j
    // xj + c*j - xi - c*i
    curr = v[0] + c;
    for (int i = 1; i < n; i++) {
        p[i] = max({0ll, p[i], -v[i] - (c * (i + 1)) + curr});
        curr = max(curr, v[i] + (c * (i + 1)));
    }
    for (ll x : p) cout << x << ' ';
}