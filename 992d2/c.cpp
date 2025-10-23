#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

void solve() {
    ll n, k;
    cin >> n >> k;
    // for n = 4, 8 instances of max, 4 instances of max 2, 4 instances of max 3, 8 instances of max 4
    // for n = 3, 4 instances of max, 2 instances of max 2
    // for n = 2, 2 instances of max
    // so for n = 5 then maybe there is 16 instances of max 1, 8 of max 2, 4 of max 3, 8 of max 4, 16 of max 4?
    // if we want the kth largest value, we can figure out where it lands

    if (k > (pow(2, n + 1) - pow(2, n - 1))) cout << -1 << "\n";

    // now sort its value

    // idk bruh
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