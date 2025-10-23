#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, s;
    cin >> k >> s;
    ll ans = 0;
    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
            int z = s - x - y;
            if (z >= 0 && z <= k) ans++;
        }
    }
    cout << ans << endl;
}