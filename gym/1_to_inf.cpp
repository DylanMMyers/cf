#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\1_to_inf.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll k; cin >> k;
        ll x = 9, y = 1, digits = 1;
        ll ans = 0;
        // handle complete sets
        while (k > x) {
            for (ll i = 1; i < 10; i++) ans += y * i;
            y *= 10;
            k -= x;
            x *= 10;
            digits++;
        }
        ll nums = y + (k/digits) - 1, extra = k % digits;
        ll carry = 0, mult = 1;
        // handle edge case of cut off number
        if (extra) {
            ll numsc = nums + 1;
            for (int i = 0; i < extra; i++) numsc /= 10;
            while (numsc > 9) {
                ans += numsc % 10;
                numsc /= 10;
            }
            ans += numsc;
        }
        // handle range of incomplete set
        ll last = nums % 10;
        nums /= 10;
        carry += last;
        for (int i = 1; i <= last; i++) ans += i;
        for (int i = digits - 1; i > 0; i--) {
            carry += nums % 10;
            nums /= 10;
            last = nums % 10;
            for (int j = 1; j < last; j++) ans += j * mult;
            ans += carry * last;
            mult *= 10;
        }
        cout << ans << "\n";
    }
}