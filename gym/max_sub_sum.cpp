#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\max_sub_sum.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll ans = LLONG_MIN, curr = 0;
    for (int i = 0; i < n; i++) {
        curr += v[i];
        ans = max(ans, curr);
        curr = max(0ll, curr);
    }
    cout << ans;
}