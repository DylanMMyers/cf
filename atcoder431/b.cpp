#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe
// g++ file.cpp -o file

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, n; cin >> x >> n;
    vector<int> w(n), used(n, 0);
    for (int i = 0; i < n; i++) cin >> w[i];
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int p; cin >> p;
        p--;
        if (used[p]) {
            x -= w[p];
            used[p] = 0;
        }
        else {
            x += w[p];
            used[p] = 1;
        }
        cout << x << "\n";
    }
}