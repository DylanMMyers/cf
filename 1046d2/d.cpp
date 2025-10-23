#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int> v(n); for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
        // can we select a singular anchor point then move ourselves based on this anchor point, guaranteeing it will the closest anchor point no matter what?
        // we only need to get above or below/left or right of an anchor point, then we can track where we've moved and its pretty trivial
        
    }
}