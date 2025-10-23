#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\to_become_max.exe

void solve() {
    ll n, k, maxi = -1;
    cin >> n >> k;
    
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    
    ll lb = 0, ub = maxi + k, ans = 0;
    while (lb <= ub) {
        ll tm = (lb + ub) / 2;
        bool good = false;
        
        for (int i = 0; i < n; i++) {
            vector<ll> min_needed(n);
            min_needed[i] = tm;
            
            ll c_used = 0;
            for (int j = i; j < n; j++) {
                if (min_needed[j] <= v[j]) break;
                
                if (j + 1 >= n) {
                    c_used = k + 1;
                    break;
                }
                
                c_used += min_needed[j] - v[j];
                min_needed[j + 1] = max(0LL, min_needed[j] - 1);
            }
            
            if (c_used <= k) good = true;
        }
        
        if (good) {
            ans = tm;
            lb = tm + 1;
        } 
        else {
            ub = tm - 1;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}