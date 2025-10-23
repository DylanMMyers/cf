#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\bal_shu.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> ps(n, 0);
    ps[0] = 0;
    unordered_map< int, vector<int> > mp;
    mp[0].push_back(0);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '(') ps[i] = ps[i - 1] + 1;
        else ps[i] = ps[i - 1] - 1;
        mp[ps[i]].push_back(i);
    }
    string ans = "";
    sort(ps.begin(), ps.end());
    int idx;
    for (int i = 0; i < n; i++) {
        idx = mp[ps[i]].back();
        mp[ps[i]].pop_back();
        ans += s[idx];
    }
    cout << ans;
}