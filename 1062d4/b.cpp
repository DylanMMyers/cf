#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        cout << (t == s ? "YES\n" : "NO\n");
    }
}