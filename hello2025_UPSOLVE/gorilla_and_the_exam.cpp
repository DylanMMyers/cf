#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\gorilla_and_the_exam.exe

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> c = {1};
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) c.back()++;
        else c.emplace_back(1);
    }

    sort(c.begin(), c.end());
    int m = c.size();
    for (int i = 0; i < c.size() - 1; i++) {
        if (c[i] > k) {
            cout << m - i << "\n";
            return;
        }
        k -= c[i];
    }
    
    cout << 1 << "\n";
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