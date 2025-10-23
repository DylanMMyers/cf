#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\digital_string_maximization.exe

void solve() {
    string s;
    cin >> s;
    int n = s.length(), curr;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(s[i] - '0');
    }
    for (int i = 1; i < n; i++) {
        curr = i;
        while (v[curr] - 1 > v[curr - 1]) {
            swap(v[curr - 1], v[curr]);
            curr--;
            v[curr]--;
            if (!curr) break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    cout << "\n";
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