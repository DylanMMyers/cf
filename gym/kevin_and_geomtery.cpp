#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\kevin_and_geomtery.exe

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int idx = -1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "-1\n";
        return;
    }
    int c = v[idx];
    v.erase(v.begin() + idx - 1, v.begin() + idx + 1);
    n -= 2;
    for (int i = 1; i < n; i++) {
        if (max(v[i], v[i - 1]) - min(v[i], v[i - 1]) < 2 * c) {
            cout << c << ' ' << c << ' ' << v[i] << ' ' << v[i - 1] << "\n";
            return;
        }
    }
    cout << "-1\n";
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