#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\shohag_loves_gcd.exe

void solve() {
    
    int n, m;
    cin >> n >> m;
 
    vector<ll> s(m + 1, 0);
 
    for(int i = 1; i <= m; i++) {
        cin >> s[i];
    }
 
    vector<ll> a(n + 1, 2);
    a[1] = 1;
 
    for(int i = 2; i <= n; i++) {
 
        for(int j = 2 * i; j <= n; j += i) {
 
            if(a[i] == a[j]) {
                a[j] = a[i] + 1;
            }
        }
    }
 
    for(int i = 1; i <= n; i++) {
        if(a[i] > m) {
            cout << -1 << endl;
            return;
        }
    }
 
    reverse(s.begin() + 1, s.end());
 
    for(int i = 1; i <= n; i++) {
        cout << s[a[i]] << " ";
    }
 
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}