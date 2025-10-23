#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\sneaky_golem.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, e, g; cin >> t >> e >> g;
    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }
    vector<int> mi(t, 0);
    mi[t - 1] = v[t - 1];
    for (int i = t - 2; i >= 0; i--) {
        mi[i] = min(e, mi[i + 1] - 1 + v[i]);
    }
    int curr = e;
    for (int i = 0; i < t; i++) {
        if (curr - mi[i] >= g) {
            cout << "YES";
            return 0;
        }
        curr -= v[i];
        curr = min(curr + 1, e);
    }
    cout << "NO";
}