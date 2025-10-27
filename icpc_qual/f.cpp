#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./f.exe
// g++ f.cpp -o f
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while (r - l >= k) {
        double average = ((long double)total) / ((double)(r - l + 1));
        if (average - v[l] > v[r] - average) total -= v[l++];
        else total -= v[r--];
    }
    double mean = ((long double)total) / ((double)k);
    double ans = 0.0;
    for (int i = l; i <= r; i++) {
        ans += (mean - v[i]) * (mean - v[i]);
    }
    cout << setprecision(6) << ans;
}