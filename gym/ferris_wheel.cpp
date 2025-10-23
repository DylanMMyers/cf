#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\ferris_wheel.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int lo = 0, ans = 0;
    for (int i = n - 1; i >= lo; i--) {
        if (i == lo) {
            ans++;
            break;
        }
        else if (v[i] + v[lo] > x) ans++;
        else {
            lo++;
            ans++;
        }
    }
    cout << ans;
}