#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\MEX_destruction.exe

void solve() {
    // 3 cases
    // all 0s (answer is 0)
    // a 0 at beginning or end (answer is 1)
    // a 0 (or multiple) not at beginning or end (answer is 2)
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int groups = 0, iter = 0;
    while (iter < n) {
        if (v[iter] != 0) {
            while (v[iter] != 0) {
                iter++;
                if (iter == n) break;
            }
            groups++;
        }
        else iter++;
    }

    if (groups == 0) cout << 0;
    else if (groups == 1) cout << 1;
    else cout << 2; 
    cout << "\n";
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