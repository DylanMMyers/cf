#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\splitcake_a_b_c.exe
// https://codeforces.com/problemset/problem/1983/C

void solve() {
    // each slice > ceil(t / 3)
    // abc, acb, bac, bca, cab, cba BRUTE FORCE

    ll n, total = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    // do all 6 permutations... redundant so didnt feel like writing

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