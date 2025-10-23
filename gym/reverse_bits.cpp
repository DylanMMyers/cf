#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve() {
    unsigned int n;
    cin >> n;
    // need to find ith bit and position it to 32-ith position
    unsigned int ans = 0;
    for (int i = 0; i < 32; i++) {
        int b = (n >> i) & 1;
        ans += b << (31 - i);
    }
    cout << ans << endl;
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