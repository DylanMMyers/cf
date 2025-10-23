#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\two_sum.exe

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
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    unordered_map<int,int,custom_hash> mp;
    for (int i = 0; i < n; i++) {
        mp[x - v[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (mp.find(v[i]) != mp.end() && mp[v[i]] != i) {
            cout << min(i, mp[v[i]]) + 1 << ' ' << max(i, mp[v[i]]) + 1;
            return 0; 
        }
    }
    cout << "IMPOSSIBLE";
}