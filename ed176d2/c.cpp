#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;
        vector<int> v(m);
        for (int i = 0; i < m; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        
        ll ans = 0;
        for (ll i = 1; i < n; i++){
            ll j = n - i;
            ll l = lower_bound(v.begin(), v.end(), i) - v.begin();
            ll cntl = m - l;
            
            ll r = lower_bound(v.begin(), v.end(), j) - v.begin();
            ll cntr = m - r;
            
            ll overlap = lower_bound(v.begin(), v.end(), max(i, j)) - v.begin();
            ll cntoverlap = m - overlap;
            
            ans += (ll)(cntl * cntr - cntoverlap);
        }
        
        cout << ans << "\n";
    }
}

// error is that i neglected intersection, should be handled in place not while calculating ans at end
// binary search approach is used, however needed to just step back a little and implement this step