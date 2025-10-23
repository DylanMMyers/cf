#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\movie_times.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    int ans = 0, lastend = -1;
    for (int i = 0; i < n; i++) {
        if (v[i].second >= lastend) {
            ans++;
            lastend = v[i].first;
        }
    }
    cout << ans;
}