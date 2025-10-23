#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y; cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cout << (a * y) / x << "\n";
    }
}