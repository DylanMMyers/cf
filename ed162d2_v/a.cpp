#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int first;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            first = i;
            break;
        }
    }
    int last;
    for (int i = n - 1; i >= first; i--) {
        if (v[i] == 1) {
            last = i;
            break;
        }
    }
    int ans = 0;
    for (int i = first + 1; i < last; i++) {
        if (v[i] == 0) ans++;
    }
    
    cout << ans << "\n";
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