#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe
// g++ c.cpp -o c

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        set<int> s, valid;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            s.insert(v[i]);
        }
        set<int> res;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (valid.find(v[i]) != valid.end()) continue;
            for (int curr = v[i]; curr <= k; curr += v[i]) {
                if (s.find(curr) == s.end()) {
                    ok = false;
                    break;
                }
                valid.insert(curr);
            }
            if (!ok) break;
            res.insert(v[i]);
        }
        if (!ok) cout << "-1\n";
        else {
            cout << res.size() << "\n";
            for (int x : res) cout << x << ' ';
            cout << "\n";
        }
    }
}