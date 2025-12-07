#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe
// g++ c.cpp -o c

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> h(n), b(m);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(h.begin(), h.end());
    sort(b.begin(), b.end());
    bool ok = true;
    for (int i = 0; i < k; i++) {
        // cout << h[i] << ' ' << b[m - k + i] << "\n";
        if (h[i] > b[m - k + i]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No");
}