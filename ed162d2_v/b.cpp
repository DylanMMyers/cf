#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int b = k, l, r;
    for (int i = 0; i < n; i++) {
        if (x[i] > 0) {
            l = i - 1;
            r = i;
            break;
        }
    }
    while (true) {
        b = k;
        while (b > 0) {
            if (x[l] > x[r]) {
                
            }
            else {

            }
        }
    }
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