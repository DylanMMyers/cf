#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        queue<vector<int>> q;
        vector<int> curr;
        ll ans = 0, currS = 0;
        for (int i = n - 1; i >= 0; i--) {
            curr.push_back(v[i]);
            currS += v[i];
            if (currS >= 0) {
                q.push(curr);
                curr.clear();
            }
        }
        if (!curr.empty()) q.push(curr);
        while (!q.empty()) {
            curr = q.front();
            for (int x : curr) {
                ans += x * q.size();
            }
            q.pop();
        }
        cout << ans << "\n";
    }
}