#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\o2.exe

void search(vector<int>& visited, int node, int parent, unordered_map<int,vector<int>> al, set<int>& currcolors, vector<int> v) {
    if (visited[node]) return;
    visited[node] = 1;

    currcolors.insert(v[node]);
    for (int i = 0; i < al[node].size(); i++) {
        if (al[node][i] == parent) continue;

        search(visited, al[node][i], node, al, currcolors, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, m, c;
        cin >> n >> m >> c;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i]--;
        }
        unordered_map<int,vector<int>> al;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        vector<int> visited(n, 0), colorcount(n, 0);
        set<int> validcolors;
        unordered_map<int,int> fullcount;
        for (int i = 0; i < n; i++) {
            set<int> currcolors;
            if (!visited[i]) search(visited, i, i, al, currcolors, v);
            else continue;

            if (!i) {
                for (auto it : currcolors) {
                    validcolors.insert((int)it);
                }
            }
            else {
                for (auto it : validcolors) {
                    if (currcolors.find((int)it) == currcolors.end()) validcolors.erase((int)it);
                }
            }
            colorcount[i] == currcolors.size();
            if (colorcount[i] == 1) {
                if (fullcount.find(v[i]) != fullcount.end()) fullcount[v[i]]++;
                else fullcount[v[i]] = 1;
            }
        }
        if (!validcolors.size()) cout << -1;
        else {
            int maxi = 0;
            for (auto it : validcolors) {
                if (fullcount.find((int)it) != fullcount.end()) maxi = max(maxi, fullcount[(int)it]);
            }
            cout << validcolors.size() - maxi;
        }
    }
}