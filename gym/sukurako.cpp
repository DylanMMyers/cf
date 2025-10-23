#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int k;
    for (int i = 0; i < q; i++) {
        cin >> k;
        // must find for each number on the test, closest we can make it to 0
        // the first number that can't be subtracted
        // locate first number that can be subtracted from, the array values shift over n - this index times?
        
    }
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