#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./e.exe
// g++ e.cpp -o e
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> score(2, 0);
    for (int i = 0; i < 10; i++) {
        // 0 == r, 1 == r
        vector<pair<double,int>> v;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            double a, b; cin >> a >> b;
            double dist = sqrt((a - 144) * (a - 144) + (b - 84) * (b - 84));
            v.push_back({dist, 0});
        }
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            double a, b; cin >> a >> b;
            double dist = sqrt((a - 144) * (a - 144) + (b - 84) * (b - 84));
            v.push_back({dist, 1});
        }
        sort(v.begin(), v.end());
        if (n + m == 0) continue;
        int color = v[0].second;
        for (int i = 0; i < v.size(); i++) {
            if (color != v[i].second) break;
            score[color]++;
        }
    }
    cout << score[0] << ' ' << score[1];
}