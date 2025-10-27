#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./j.exe
// g++ file.cpp -o file
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 100;
    for (int i = 0; i < 99; i++) {
        int tr; cin >> tr;
    }
    int ans; cin >> ans;
    if (!(ans % 10)) cout << 10;
    else cout << ans % 10;
}