#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\fix_flooded_floor.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<string> v(2); cin >> v[0] >> v[1];
        vector<string> ansc = {"None\n", "Unique\n", "Multiple\n"};
        int ans = 1; // 0, 1, 2 -> none, unique, multiple
        // what to do
        cout << ansc[ans];
    }
}