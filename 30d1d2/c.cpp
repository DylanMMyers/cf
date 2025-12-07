#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe
// g++ c.cpp -o c

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
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m), c(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < m; i++) cin >> c[i];
        vector<pair<int,int>> mon(m);
        for (int i = 0; i < m; i++) {
            mon[i].first = b[i];
            mon[i].second = c[i];
        }
        vector<int> zer;
        sort(mon.begin(), mon.end());
        int ans = 0;
        unordered_map<int,int,custom_hash> ct;
        set<int> sw;
        for (int i = 0; i < n; i++) {
            if (ct.find(a[i]) != ct.end()) ct[a[i]]++;
            else ct[a[i]] = 1;
            sw.insert(a[i]);
        }
        for (int i = 0; i < m; i++) {
            auto x = sw.lower_bound(mon[i].first);
            if (x == sw.end()) break;
            if (!mon[i].second) {
                zer.push_back(mon[i].first);
                continue;
            }
            ans++;
            if (mon[i].second > *x) {
                ct[*x]--;
                if (!ct[*x]) sw.erase(*x);
                sw.insert(mon[i].second);
                if (ct.find(mon[i].second) != ct.end()) ct[mon[i].second]++;
                else ct[mon[i].second] = 1;
            }
        }
        vector<int> newa;
        for (int x : sw) {
            for (int i = 0; i < ct[x]; i++) {
                newa.push_back(x);
            }
        }
        int s = 0, zidx = 0;
        while (s < n && zidx < zer.size()) {
            if (newa[s] >= zer[zidx]) {
                ans++;
                s++;
                zidx++;
            }
            else {
                s++;
            }
        }
        cout << ans << "\n";
    }
}