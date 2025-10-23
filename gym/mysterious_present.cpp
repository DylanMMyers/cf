#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\mysterious_present.exe

int MOD = 1e8;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, h; cin >> n >> w >> h;
    vector<pair<int,int>> v(n); for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    // base case is using the smallest envelope first
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
}