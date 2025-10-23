#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // i think it can be proven that its always beneficial to minimize the current element
    // problem arises when we reach an element that is greater than the next, we go k, k - 1, k + something
    // can just be greedy when sorting then iterate later and see if our approach worked

    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            v[i] -= v[i + 1];
            v[i + 1] = 0;
        }
        else {
            v[i + 1] -= v[i];
            v[i] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            cout << "NO\n";
            return;
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