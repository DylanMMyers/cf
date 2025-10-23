#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve() {
    unsigned int n;
    cin >> n;
    for (int i = 0; i < 32; i += 2) {
        int lb = (n >> i) & 1;
        int rb = (n >> (i + 1)) & 1;
        n = n - (lb << i) - (rb << (i + 1)) + (lb << (i + 1)) + (rb << i);
        // remove the left bit and right bit (uses the fact that 1111 - 0010 = 1101)
        // add the bits back in their respective opposite positions
    }
    cout << n << endl;
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