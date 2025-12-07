#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe
// g++ a.cpp -o a

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int x; cin >> x;
        int gre = false, le = false;
        for (int i = 0; i < n; i++) {
            if (v[i] >= x) gre = true;
            if (v[i] <= x) le = true;
        }
        cout << (gre && le ? "YES\n" : "NO\n");
    }
}