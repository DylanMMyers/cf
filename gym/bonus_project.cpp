#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\bonus_project.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<ll> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i - 1] / b[i - 1];
    }
    if (ps[n] < k) {
        for (int i = 0; i < n; i++) {
            cout << '0' << " \n"[ i == n - 1];
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int x = ps[n] - ps[i], y = ps[i] - ps[i - 1]; // x = later hours available
        // since everyone acts greedily, they will do up to k - x hours
        if (k < x) {
            cout << '0' << " \n"[i == n];
        }
        else {
            cout << min(y, k - x) << " \n"[i == n];
            k -= min(y, k - x);
        }
    }
}