#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, s;
        cin >> n >> s;
        vector<<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            v[i] = {dx, dy, x, y};            
        }
        
    }
}