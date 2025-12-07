#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe
// g++ c.cpp -o c

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<pair<int,int>> neighbor(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                neighbor[i].first = n - 1;
                neighbor[i].second = 1;
            }
            else if (i == n - 1) {
                neighbor[i].first = n - 2;
                neighbor[i].second = 0;
            }
            else {
                neighbor[i].first = i - 1;
                neighbor[i].second = i + 1;
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        ll ans = 0;
        int it = 0;
        for (int i = 0; i < n; i++) {
            pq.push({v[i], i});
        }
        while (it < n - 1) {
            int idx = pq.top().second;
            pq.pop();
            int l = neighbor[idx].first, r = neighbor[idx].second;
            if (v[l] <= v[r]) {
                ans += v[l];
                neighbor[l].second = neighbor[idx].second;
                neighbor[neighbor[idx].second].first = l;
            }
            else {
                ans += v[r];
                neighbor[r].first = neighbor[idx].first;
                neighbor[neighbor[idx].first].second = r;
            }
            it++;
        }
        cout << ans << "\n";
    }
}