#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\cppspeed.exe
// g++ cppspeed.cpp -o cppspeed

int main() {
    ll n = 1e9, ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i;
    }
    cout << ans;
}