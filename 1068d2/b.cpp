#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        ll k1 = 0, k2 = 0;
        for (int i = 0; i < n; i++) {
            ll curr1 = max(k1 - a[i], b[i] + k2);
            ll curr2 = max(k2 + a[i], k1 - b[i]);
            k1 = curr1;
            k2 = curr2;
        }
        cout << k1 << "\n";
    }
}