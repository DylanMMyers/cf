#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    int ans = 1;
    while (n >= 1) {
        ans++;
        if (n % 2) {
            n /= 2;
            n++;
        }
    }
    cout << ans;
}