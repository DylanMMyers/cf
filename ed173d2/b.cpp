#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    int n, d;
    cin >> n >> d;
    cout << 1;
    // x
    // xx
    // xxxxxx
    // xxxxxxxxxxxxxxxxxxxxxxxx
    set<int> s;
    
    if (d % 2 == 1) s.insert(d);
    if (n > 2 || d == 6 || d == 9) s.insert(3);
    if (n > 5) s.insert(7), s.insert(9);
    if (d == 3 && n > 2) s.insert(9);
    if (n > 6) {
        s.insert(3);
        s.insert(7);
        s.insert(9);
    }
    
    for (int ele : s) {
        if (ele == 1) continue;
        cout << ' ' << ele;
    }
    cout << "\n";
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