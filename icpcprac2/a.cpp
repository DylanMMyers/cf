#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    long double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += v[i];
    }
    long double downloaded = 0.0;
    for (int i = 0; i < min(m + k, n); i++) {
        downloaded += v[i];
    }
    cout << setprecision(15);
    cout << (long double)100 * (downloaded / total);
}