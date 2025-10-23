#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\dgpt.exe

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt = 1;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        vector<ll> centers(n);
        vector<int> radii(n);
        for (int i = 0; i < n; i++){
            cin >> centers[i];
        }
        for (int i = 0; i < n; i++){
            cin >> radii[i];
        }
        unordered_map<ll, int> coverage;
        for (int i = 0; i < n; i++){
            ll cx = centers[i];
            int r = radii[i];
            ll start = cx - r;
            ll end = cx + r;
            for (ll x = start; x <= end; x++){
                ll dx = x - cx;
                ll rem = (ll)r * r - dx * dx;
                int d = (int)floor(sqrt((long double)rem));
                coverage[x] = max(coverage[x], d);
            }
        }
        ll res = 0;
        for(auto &entry : coverage) {
            res += 2LL * entry.second + 1LL;
        }

        cout << res << "\n";
    }
}