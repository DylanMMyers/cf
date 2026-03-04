#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int z = 0, o = 0;
        vector<int> zidx;
        for (int i = 0; i < n; i++) {
            if (v[i]) o++;
            else {
                zidx.push_back(i);
                z++;
            }
        }
        int mv = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                if (zidx.empty() || zidx.back() < i) break;
                else {
                    v[zidx.back()] = 1;
                    v[i] = -1;
                    zidx.pop_back();
                    mv++;
                }
            }
        }
        cout << min({o, z, mv}) << '\n';
    }
}