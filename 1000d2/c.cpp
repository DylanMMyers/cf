#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

void dfs(unordered_map<int,vector<int>> al, int level, int n, set<int> s) {
    
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> its;
    unordered_map<int, int> level;
    for (int i = 1; i <= n; i++) {
        its.push_back(i);
        level[i] = -1;
    }
    level[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i].first >> v[i].second;
        if (level[v[i].first] == -1 && level[v[i].second] == -1) continue;
        else if (level[v[i].first] == -1) level[v[i].first] = level[v[i].second] + 1;
        else level[v[i].second] = level[v[i].first] + 1;
    }
    
    if (n <= 2) {
        cout << "0\n";
        return;
    }
    if (n == 3) {
        cout << "1\n";
        return;
    }
    // create al
    unordered_map<int, vector<int>> al;
    for (int i = 0; i < n - 1; i++) {
        al[v[i].first].push_back(v[i].second);
        al[v[i].second].push_back(v[i].first);
    }    

    // find deepest two nodes with highest degree, greedily remove
    int maxi = 0, idx = 1, curr, ans = 1;
    for (auto x : its) {
        curr = al[x].size();
        if (curr == maxi) {
            if (level[x] > level[idx]) {
                maxi = curr;
                idx = x;
            }
        }
        else if (curr > maxi) {
            maxi = curr;
            idx = x;
        }
    }

    ans += maxi - 1;

    unordered_map<int,vector<int>> al2;
    for (int i = 0; i < n - 1; i++) {
        if (v[i].first == idx || v[i].second == idx) continue;
        else {
            al2[v[i].first].push_back(v[i].second);
            al2[v[i].second].push_back(v[i].first);
        }
    }

    maxi = -1, idx = 1;
    for (auto x : its) {
        curr = al2[x].size();
        if (curr > maxi) {
            maxi = curr;
            idx = x;
        }
        else if (curr == maxi) {
            if (level[x] > level[idx]) {
                maxi = curr;
                idx = x;
            }
        }
    }
    ans += maxi - 1;

    cout << ans << "\n";
    if (ans == 2 && n == 5) {
        for (int i = 0; i < n - 1; i++) {
            cout << v[i].first << ' ' << v[i].second << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}