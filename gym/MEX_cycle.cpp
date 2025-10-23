#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\MEX_cycle.exe

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> mex(n);
    // we set each value alternating as 0 or 1, we do this because initially we can say the numbers next to it will contain two 0s or a two ones
    // then, depending on constraints of if n is odd or even or if x - y is odd or even, this would cause two ones to neighbor with a 0 next door so 2 becomes mex
    x--, y--;

    for (int i = 0; i < n; i++) {
        mex[(x + i) % n] = i % 2;
    }

    if (n % 2 || (x - y) % 2 == 0) mex[x] = 2;

    for (int i = 0; i < n; i++) {
        cout << mex[i] << ' ';
    }
    
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