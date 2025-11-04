#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\3sum_mod.exe
// g++ 3sum_mod.cpp -o 3sum_mod

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d; cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    unordered_map<int,vector<int>> mp;
    for (int i = 0; i < n; i++) {
        // for each index, we want to denote the count of k elements which 
        int x = v[i];
        x = (d - (x % d)) % d;
        mp[x].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int dist = (d - (v[i] + v[j]) % d) % d;
            if (mp.find(dist) != mp.end()) {
                auto k = upper_bound(mp[dist].begin(), mp[dist].end(), j);
                if (k == mp[dist].end()) continue;
                ans += mp[dist].end() - k;
            }
        }
    }
    cout << ans;
}