#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\vika_and_price_tags.exe

int gcd(int a, int b) {
    if (a == 0) return 0;
    if (b == 0) return 1;
    if (a >= b) {
        int r = a % b;
        int k = a / b;
        if (k % 2 == 1) return gcd(b, r) + k + k / 2;
        else return gcd(r, b) + k + k / 2;
    }
    return 1 + gcd(b, abs(a - b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        // all numbers can reach 0, but will alternate some times between 0 and !0
        // then we should figure out if some numbers can ever be pairs on the same turn
        // so is it alternating 1 0 1 0 ... or is it potentially a b c 0 a b c 0 ...
        // always 1 0 1 0 ...
        // we will mark res with 1 if it occurs on even parity, 2 if odd
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (!a[i] && !b[i]) continue;
            s.insert(gcd(a[i], b[i]) % 3);
        }
        cout << (s.size() <= 1 ? "YES\n" : "NO\n");
    }
}