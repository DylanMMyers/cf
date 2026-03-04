#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\restricted_sorting.exe
// g++ restricted_sorting.cpp -o restricted_sorting

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int vmax = *max_element(v.begin(), v.end());
        int vmin = *min_element(v.begin(), v.end());
        int ans = 1e9;
        vector<int> sv = v; 
        sort(sv.begin(), sv.end());
        for (int i = 0; i < n; i++) {
            if (v[i] != sv[i]) {
                ans = min(ans, max(vmax - v[i], (vmin - v[i]) * -1));
            }
        }
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
}