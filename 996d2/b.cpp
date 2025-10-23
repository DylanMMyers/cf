#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    // just keep a running count of subtractions that are necessary, be greedy, check at end if all elements satsify their b_i
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = a[i] - b[i];
    } 
    sort(v.begin(), v.end());
    ll run = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < 0) run -= v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] < 0) v[i] = 0 - (run + v[i]);
        else v[i] -= run;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}