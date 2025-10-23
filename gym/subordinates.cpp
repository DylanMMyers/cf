#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\subordinates.exe

unordered_map<int, vector<int>> al;
vector<int> v;

int dfs (int curr) {
    if (!al[curr].size()) {
        v[curr] = 0;
        return 0;
    }

    v[curr] = 0;
    for (int i = 0; i < al[curr].size(); i++) {
        v[curr] += dfs(al[curr][i]) + 1;
    }
    return v[curr];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        v.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            al[x].push_back(i);
        }
        v[1] = dfs(1);
        for (int i = 1; i <= n; i++) {
            cout << v[i] << ' ';
        }
    }
}