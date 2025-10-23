#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        auto split = [&](int l, int r) -> vector<ll> {
            int len = r - l + 1;
            vector<ll> res;

            for (int i = 0; i < (1 << len); i++) {
                ll sum = 0;
                for (int j = 0; j < len; j++) {
                    if (i & (1 << j)) sum += v[l + j];
                }
                res.push_back(sum);
            }

            return res;
        };

        vector<ll> left = split(0, n / 2 - 1);
        vector<ll> right = split(n / 2, n - 1);
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        ll ans = 0;
        for (ll i : left) { 
            auto low_it = lower_bound(right.begin(), right.end(), x - i);
            auto high_it = upper_bound(right.begin(), right.end(), x - i);
            ans += high_it - low_it;    
        }

        cout << ans << "\n";
    }
}