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

    // if from any given clock the time required to travel to all other clocks and return exceeds the clocks initial value, no
    // otherwise yes
    // we can find the min, and if any dist requires us to travel longer than that of satisfying the min clock, NO
    
    for (int i = 0; i < n; i++) {
        if (v[i] <= 2 * (n - i - 1) || v[i] <= 2 * i) {
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