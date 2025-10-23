#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\xor_sum.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> xs(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            xs[i] = xs[i - 1] ^ v[i - 1];
        }
        int a, b;
        for (int i = 0; i < q; i++) {
            cin >> a >> b;
            int curr = xs[a - 1] ^ xs[b];
            cout << curr << "\n";
        }
    }
}