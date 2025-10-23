#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

// wow so fun! i love custom hash functions! i love hacking phase!
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
        ll n, k; cin >> n >> k;
        vector<ll> s(n);
        set<ll> t;
        unordered_map<ll, ll, custom_hash> ct;
        for (int i = 0; i < n; i++) cin >> s[i]; 
        ll inp;
        for (int i = 0; i < n; i++) {
            cin >> inp;
            inp %= k;
            t.insert(inp);
            if (ct.find(inp) == ct.end()) ct[inp] = 1;
            else ct[inp]++;
        } 
        // if t_i % k is in S, we remove s_i and t_i OR if |s_i - k| is in t, we remove s_i and t_i
        for (int i = 0; i < n; i++) s[i] %= k;
        for (int i = 0; i < n; i++) {
            ll x = s[i], y = max(s[i], k) - min(s[i], k);
            if (ct.find(x) != ct.end()) {
                ct[x]--;
                if (!ct[x]) {
                    t.erase(x);
                    ct.erase(x);
                }
            }
            else if (ct.find(y) != ct.end()) {
                ct[y]--;
                if (!ct[y]) {
                    t.erase(y);
                    ct.erase(y);
                }
            }
        }
        cout << (t.size() == 0 ? "YES\n" : "NO\n");
    }
}