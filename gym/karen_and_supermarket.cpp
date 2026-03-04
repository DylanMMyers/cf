#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\karen_and_supermarket.exe
// g++ karen_and_supermarket.cpp -o karen_and_supermarket

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, b; cin >> n >> b;
    vector<ll> c(n), d(n), x(n);
    cin >> c[0] >> d[0];
    x[0] = -1;
    for (int i = 1; i < n; i++) {
        cin >> c[i] >> d[i] >> x[i];
        x[i]--;
    }
    // create toposort tree and dp on toposort tree to determine cost (if we must use coupons
    // then must also purchase these items at the discounted price) of buying this item with the coupon
    // need to consider all paths down the tree, including the cost of each path and how many items they yield
    

    // LOLSKILL ISSUE
}