#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\xor_ps.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] ^ v[i - 1];
    }
    // iterate through the xor of prev value and curr value
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << (ps[b] ^ ps[a - 1]) << "\n";
    }
    // because the xor sum would be all the previous and the curr anyway, we would end up at a - 1
    // we can then reduce extra calculations as the cancel out, so just output endpoints of desired xor sum
}