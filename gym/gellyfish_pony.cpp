#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\gellyfish_pony.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        int gcdv = v[0];
        for (int i = 1; i < n; i++) {
            gcdv = __gcd(gcdv, v[i]);
        }
        // next, its the minimum moves for one element to become the gcdv + turning all the other elements into gcdv
        
    }
}