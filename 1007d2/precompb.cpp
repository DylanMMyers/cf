#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

int main() {
    ll sum = 0;
    for (ll i = 1; i <= 6e5; i++) {
        sum += i;
        for (ll j = 1; j * j <= sum; j++) {
            if (j * j == sum) {
                cout << i << ' ';
            }
        }
    }
}
