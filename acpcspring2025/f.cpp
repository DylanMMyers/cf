#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

ll helper(vector<vector<ll>>& comp, vector<vector<ll>> c, vector<vector<ll>> h, ll i, ll j) {
    if (comp[i][j]) return 0;

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<vector<ll>> c(vector<ll>(n)), h(vector<ll>(n));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cin >> c[i][j];
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cin >> h[i][j];
            }
        }
        ll ans = 50000000000000;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                vector<vector<ll>> comp = {{0,0,0},{0,0,0},{0,0,0}};
                ans = min(ans, helper(comp, c, h, i, j));
            }
        }
    }
}