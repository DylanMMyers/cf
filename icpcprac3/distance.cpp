#include <bits/stdc++.h>
#define ll long long
using namespace std;
// g++ distance.cpp -o distance
// Get-Content t.txt | .\distance.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll currx = 0, curry = 0;
    ll xa = 0, ya = 0;
    for (int i = 1; i < n; i++) {
        ll dist = x[i] - x[i - 1];
        currx += dist * i;
        xa += currx;
    }
    for (int i = 1; i < n; i++) {
        ll dist = y[i] - y[i - 1];
        curry += dist * i;
        ya += curry;
    }
    cout << xa + ya;
}