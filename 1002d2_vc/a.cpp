#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        set<int> a, b;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            b.insert(x);
        }
        if (a.size() >= 3 || b.size() >= 3 || (a.size() >= 2 && b.size() >= 2)) cout << "YES\n";
        else cout << "NO\n";
    }
}