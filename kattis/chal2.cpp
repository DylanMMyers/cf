#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n1, n2, m1, m2; cin >> n1 >> n2 >> m1 >> m2;
    vector<vector<int>> al1(n1), al2(n2);
    int u, v;
    for (int i = 0; i < m1; i++) {
        cin >> u >> v;
        u--;
        v--;
        al1[u].push_back(v);
    }
    for (int i = 0; i < m2; i++) {
        cin >> u >> v;
        u--;
        v--;
        al2[u].push_back(v);
    }
    vector<set<int>> s1(n1), s2(n2);
    queue<pair<int,int>> q;
    int dist, node;
    q.push({0, 0});
    while (!q.empty()) {
        dist = q.front().first, node = q.front().second;
        q.pop();
        if (s1[node].find(dist) != s1[node].end()) continue;
        s1[node].insert(dist);
        for (int i = 0; i < al1[node].size(); i++) {
            q.push({dist + 1, al1[node][i]});
        }
    }
    q.push({0, 0});
    while (!q.empty()) {
        dist = q.front().first, node = q.front().second;
        q.pop();
        if (s2[node].find(dist) != s2[node].end()) continue;
        s2[node].insert(dist);
        for (int i = 0; i < al2[node].size(); i++) {
            q.push({dist + 1, al2[node][i]});
        }
    }
    int qu; cin >> qu;
    for (int i = 0; i < qu; i++) {
        int qq; cin >> qq;
        if (s1[n1 - 1].find(qq) != s1[n1 - 1].end() && s2[n2 - 1].find(qq) != s2[n2 - 1].end()) cout << "Yes\n";
        else cout << "No\n";
    }
}