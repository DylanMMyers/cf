#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> check(n);

    for (int i = 2; i < n; i++) {
        if (v[i - 2] + v[i - 1] == v[i]) check[i] = 1;
        else check[i] = 0;
    }

    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        if (check[i] == 1) curr++;
        else curr = 0;
        ans = max(ans, curr);
    }

    if (n == 1 || n == 2) cout << n << endl;
    else cout << ans + 2 << endl;

}