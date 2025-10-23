#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        // now lets iterate and see what the greedy max is we can make, then we will attempt to work backwards for if we have a mex missing?
        priority_queue<int, vector<int>, greater<int>> pq;
        int curr;
        for (int i = 0; i < n; i++) {
            curr = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (v[i][j] == 1) curr++;
                else break;
            }
            pq.push(curr);
        }
        int ans = 0;
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            if (ans <= curr) ans++;
        }
        cout << ans << "\n";
    }
}