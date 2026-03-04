#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\prime_factor.exe
// g++ prime_factor.cpp -o prime_factor

bool isprime(int x) {
    for (int i = 2; i < x; i++) {
        if (!(x % i)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        __int128 n, curr = 2; cin >> n;
        while (n > 1) {
            if (n % curr) {
                curr++;
                while (!isprime(curr) || n % curr) {
                    curr++;
                }
            }
            n /= curr;
            cout << curr << ' ';
        }
    }
}