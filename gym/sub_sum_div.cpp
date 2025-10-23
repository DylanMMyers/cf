#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\sub_sum_div.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, l; cin >> n >> m >> l;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ps(n + 1, 0), sl(n - l + 1, 0);
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + v[i - 1];
    for (int i = 0; i <= n - l; i++) sl[i] = ps[i + l] - ps[i];
    for (int x : sl) cout << x << ' ';
    cout << "\n";
    ll ans = 0;
    for (int i = 0; i < n - l + 1; i++) {
        if (!(sl[i] % m)) continue;
        int j = i;
        while (j < n - l) {
            if ((sl[j] % m) < (sl[i] % m)) break;
            j++;
        }
        // now we have latest idx where we can 
    }
    cout << ans << "\n";
    for (int x : sl) cout << x << ' ';
}

// this is all wrong btw
// revisit