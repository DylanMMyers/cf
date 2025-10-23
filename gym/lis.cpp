#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\lis.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), v[i]);
        if (it == dp.end()) dp.push_back(v[i]);
        else *it = v[i];
    }
    cout << dp.size();
}