#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        if (a == b) cout << "0\n";
        else {
            if (a > b) swap(a, b);
            if (b % a) cout << "2\n";
            else cout << "1\n";
        }
    }
}
// 1:40