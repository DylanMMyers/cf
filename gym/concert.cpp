#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\concert.exe

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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    set<int> st;
    unordered_map<int,int,custom_hash> ct;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        if (ct.find(a[i]) == ct.end()) ct[a[i]] = 1;
        else ct[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        auto x = st.upper_bound(b[i]);
        if (x == st.begin()) cout << "-1\n";
        else {
            x--;
            cout << *x << "\n";
            if (!--ct[*x]) st.erase(*x);
        }
    }
}