#include <bits/stdc++.h>
#define ll long long
using namespace std;
// g++ stop.cpp -o stop
// Get-Content t.txt | .\stop.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    bool on = false;
    ll ans = 0;
    cin >> v[0];
    on = true;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        if (!on) on = true;
        else {
            ans += v[i] - v[i - 1];
            on = false;
        }
    }
    if (on) cout << "still running";
    else cout << ans;
}