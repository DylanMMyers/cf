#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    int n;
    cin >> n;
    int a, b;
    vector<int> v(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (mp.find(v[i]) == mp.end()) mp[v[i]] = 1;
        else mp[v[i]]++;
    }
    if (n == 3) {
        cout << 1 << ' ' << 1 << "\n";
        return;
    }
    for (int x : v) {
        if (x == 1 && (mp.find(n - 2) != mp.end())) {
            a = x;
            break;
        }

        else if ((x != 1) && ((n - 2) % x == 0) && (mp.find((n - 2) / x) != mp.end())) {
            if ((n - 2) / x == x) {
                if (mp[x] < 2) continue;
            } 
            a = x;
            break;
        }
    }
    b = (n - 2) / a;
    cout << a << ' ' << b << "\n";
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