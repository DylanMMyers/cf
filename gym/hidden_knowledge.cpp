#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\hidden_knowledge.exe

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k, l, r; cin >> n >> k >> l >> r;
        vector<int> v(n);
        unordered_map<int,int,custom_hash> xc, yc;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            xc[v[i]] = 0;
            yc[v[i]] = 0;
        }
        ll ans = 0;
        int x = 0, y = 0, xit = 0, yit = 0;
        for (int i = 0; i < n; i++) {
            while (x < k && xit < n) {
                if (xc[v[xit]] == 0) {
                    xc[v[xit]] = 1;
                    x++;
                }
                else xc[v[xit]]++;
                xit++;
            }
            while (y < k && yit < n) {
                if (yc[v[yit]] == 0) {
                    yc[v[yit]] = 1;
                    y++;
                }
                else yc[v[yit]]++;
                yit++;
            }
            while (yit < n && yc[v[yit]]) {
                yc[v[yit]]++;
                yit++;
            }
            if (x == k) ans += max(0, min(yit - 1, i + r - 1) - max(xit - 1, i + l - 1) + 1);
            if (--xc[v[i]] == 0) x--;
            if (--yc[v[i]] == 0) y--;
        }
        cout << ans << "\n";
    }
}