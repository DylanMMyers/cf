#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
// Get-Content t.txt | .\c.exe
// g++ c.cpp -o c

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ull s, m; cin >> s >> m;
        bool ok = true;
        for (int i = 0; i < 63; i++) {
            if ((m >> i) & 1) break;
            if ((s >> i) & 1) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        ull low = 0, high = 1e18;
        while (low < high) {
            ull mid = (low + high) / 2, currs = s;
            for (int i = 63; i >= 0; i--) {
                ull x = (1ll << i) & m;
                if (!x) continue;
                ull count = currs / x;
                currs -= min(count, mid) * x;
            }
            if (!currs) high = mid;
            else low = mid + 1;
        }
        cout << low << '\n';
    }
}