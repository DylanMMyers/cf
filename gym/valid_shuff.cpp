#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> ps(n, 0);
    ps[0] = 0;
    unordered_map< int, vector<int> > mp;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '(') ps[i] = ps[i - 1] + 1;
        else ps[i] = ps[i - 1] - 1;
        mp[ps[i]].push_back(i);
    }
    string ans = "";
    sort(ps.begin(), ps.end());
    for (int i = 0; i < n; i++) {
        ans += mp[s[i]][mp[ps[i].size()]];
        mp[ps[i]].pop_back();
    }
    cout << ans;
}