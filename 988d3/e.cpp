#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\e.exe

void solve() {
    int n, x;
    cin >> n;
    vector<int> v;
    // 00, 10, 11, 01
    // 
    int l = 1, r = n;
    while (l < r) {
        cout << "? " << l << ' ' << r << "\n";
        cout.flush();
        cin >> x;
        v.push_back(x);
        
    }
    cout << 1;
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