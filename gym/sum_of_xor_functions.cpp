#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\sum_of_xor_functions.exe

ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> xorps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        xorps[i] = xorps[i - 1] ^ v[i - 1];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans += ((xorps[j] ^ xorps[i - 1]) * (j - i + 1));
            ans = ans % MOD;
        }
    }

    cout << ans;
}