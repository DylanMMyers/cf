#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\turtle_and_incomplete_sequence.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; i++) {
            if (v[i] > -1) pq.push({v[i], i});
        }
        if (pq.empty()) {
            v[0] = 1;
            pq.push({1, 0});
        }
        while (!pq.empty()) {
            pair<int,int> curr = pq.top();
            pq.pop();
            if (curr.second > 0) {
                if (v[curr.second - 1] == -1) {
                    if (v[curr.second] == 1) v[curr.second - 1] = 2;
                    else v[curr.second - 1] = curr.first / 2;
                    pq.push({v[curr.second - 1], curr.second - 1});
                }
            }
            if (curr.second < n - 1) {
                if (v[curr.second + 1] == -1) {
                    if (v[curr.second] == 1) v[curr.second + 1] = 2;
                    else v[curr.second + 1] = curr.first / 2;
                    pq.push({v[curr.second + 1], curr.second + 1});
                }
            }
        }
        bool bad = false;
        int c = 2;
        for (int i = 1; i < n; i++) {
            c = 2;
            if ((v[i] / 2) != v[i - 1]) c--;
            if ((v[i - 1] / 2) != v[i]) c--;
            if (!c) {
                bad = true;
                break;
            }
        }
        if (bad) cout << "-1\n";
        else {
            cout << v[0];
            for (int i = 1; i < n; i++) {
                cout << ' ' << v[i];
            }
            cout << "\n";
        }
    }
}