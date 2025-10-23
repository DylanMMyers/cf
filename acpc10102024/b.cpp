#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll maxi1 = 0, maxi2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= maxi1) {
            maxi2 = maxi1;
            maxi1 = v[i];
        }
        else if (v[i] >= maxi2) maxi2 = v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == maxi1) cout << v[i] - maxi2 << ' ';
        else cout << v[i] - maxi1 << ' ';
    }
    cout << endl;
}
 
int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}