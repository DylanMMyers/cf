#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\sqrt_decomp.exe
// g++ sqrt_decomp.cpp -o sqrt_decomp

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int blocks = (int) sqrt(n + .0) + 1;
    vector<ll> s(blocks, 0);
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int a, b, u; cin >> a >> b >> u;
            a--;
            b--;
            for (int j = a; j <= b; ) {
                if (j % blocks == 0 && i + blocks <= b) {
                    s[j / blocks] += u;
                    j += blocks;
                }
                else {
                    v[j] += u;
                    j++;
                }
            }
        }
        else if (op == 2) {
            int k; cin >> k;
            k--;
            cout << s[k / blocks] + v[k] << "\n";
        }
    }
}