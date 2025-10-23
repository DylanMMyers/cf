#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // 5 1 2 3 4
    // 3 1 2
    // 3 2 1
    // 2 1 3
    // 5 7 6
    // if an element is more than itself minus its current position from its correct position, cant possibly be sorted
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            if (v[i] - 1 == v[i + 1]) swap(v[i], v[i + 1]);
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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