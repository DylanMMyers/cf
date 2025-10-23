#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

bool hassev(ll n) {
    while (n > 9) {
        ll curr = n % 10;
        n /= 10;
        if (curr == 7) return true;
    }
    if (n == 7) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<int> v;
        ll temp = n;
        while (n > 9) {
            ll curr = n % 10;
            n /= 10;
            v.push_back(curr);
        }
        v.push_back(n);
        reverse(v.begin(), v.end());
        ll ans = 7;
        if (hassev(temp)) ans = 0;
        vector<ll> pow = {9,90,900,9000,90000,900000,9000000,90000000,900000000,9000000000,90000000000};
        for (int i = 1; i <= v.size() + 1; i++) {
            ll it = 0, f = 0, curr = temp;
            for (int j = 0; j < i; j++) {
                f += pow[j];
            }
            while (!hassev(curr)) {
                curr += f;
                it++;
            }
            ans = min(it, ans);
        }
        cout << ans << "\n";
    }
}

// 3 7