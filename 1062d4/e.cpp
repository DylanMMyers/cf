#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\e.exe
// g++ e.cpp -o e

int find_dist(vector<int>& v, int pos) {
    auto it = lower_bound(v.begin(), v.end(), pos);
    if (it == v.end()) return pos - v.back();
    if (it == v.begin()) return v.front() - pos;
    int l = *(it - 1), r = *it;
    return min(pos - l, r - pos);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k, x; cin >> n >> k >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        priority_queue<pair<int,int>> pq;
        set<int> vis;
        for (int i = 0; i < n; i++) {
            pq.push({0, v[i]});
            vis.insert(v[i]);
        }
        if (vis.find(0) == vis.end()) {
            pq.push({v[0], 0});
            vis.insert(0);
        }
        if (vis.find(x) == vis.end()) {
            pq.push({x - v.back(), x});
            vis.insert(x);
        }
        for (int i = 1; i < n; i++) {
            int dist = v[i] - v[i - 1];
            if (vis.find(v[i - 1] + (dist / 2)) == vis.end()) {
                int ndist = find_dist(v, v[i - 1] + (dist / 2));
                pq.push({ndist, v[i - 1] + (dist / 2)});
                vis.insert(v[i - 1] + (dist / 2));
            }
            if (vis.find(v[i] - (dist / 2)) == vis.end()) {
                int ndist = find_dist(v, v[i] - (dist / 2));
                pq.push({ndist, v[i] - (dist / 2)});
                vis.insert(v[i] - (dist / 2));
            }
            if (dist % 2) {
                if (vis.find(v[i - 1] + (1 + dist / 2)) == vis.end()) {
                    int ndist = find_dist(v, v[i - 1] + (1 + dist / 2));
                    pq.push({ndist, v[i - 1] + (1 + dist / 2)});
                    vis.insert(v[i - 1] + (1 + dist / 2));
                }
                if (vis.find(v[i] - (1 + dist / 2)) == vis.end()) {
                    int ndist = find_dist(v, v[i] - (1 + dist / 2));
                    pq.push({ndist / 2, v[i] - (1 + dist / 2)});
                    vis.insert(v[i] - (1 + dist / 2));
                }
            }
        }
        set<int> final_pos;
        while (final_pos.size() < k) {
            int dist = pq.top().first, pos = pq.top().second;
            pq.pop();
            final_pos.insert(pos);
            if (vis.find(pos + 1) == vis.end() && pos + 1 <= x) {
                int ndist = find_dist(v, pos + 1);
                pq.push({ndist, pos + 1});
                vis.insert(pos + 1);
            }
            if (vis.find(pos - 1) == vis.end() && pos - 1 >= 0) {
                int ndist = find_dist(v, pos - 1);
                pq.push({ndist, pos - 1});
                vis.insert(pos - 1);
            }
        }
        for (int x : final_pos) {
            cout << x << ' ';
        }
        cout << "\n";
    }
}