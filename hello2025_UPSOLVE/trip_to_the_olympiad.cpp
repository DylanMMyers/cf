#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\trip_to_the_olympiad.exe

void solve() {
    // most leftmost opposite bits
    int l, r;
    cin >> l >> r;
    int a = 0, b = 0, c = 0;
    // does mazimizing a ^ b and then b ^ c also maximize b ^ c?
    // we want an a and b as close to 100...000 and 011...111 as we can get
    // then we can fit c to maximize these values in O(n) time?
    
    // construct a, get as many left most bits as we can, not necessarily the maxi

    // ANS: wrong, we should try to find unique bits for each i of 2^i, the score can be described for a given bit as 2 * 2^i
    // if it appears every time or not at all, it harms our answer
    // we want every bit to appear 1 or 2 times that way we reach the max answer
    
    int k = 31 - __builtin_clz(l ^ r); // count leading zeroes (on the left), subtract from 31 to find kth most significant unique bit
    // 0 2 -> 00 10
    a = l | ((1 << k) - 1); // l and our most significant unique bit -> 00 | (1 << 1) - 1 = 1, so l | 1 = 0 | 1 = 1
    b = a + 1; // the next number -> 2, 10 and 01 maximize a ^ b
    c = (a == l ? r : l); // any other number, in this case 0 as 00 maximizes a ^ c and b ^ c

    // essentially, a bit 

    cout << a << ' ' << b << ' ' << c << "\n";
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