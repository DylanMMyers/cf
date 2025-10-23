#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\tree_jumps.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int,vector<int>> children;
        for (int i = 1; i < n; i++) {
            cin >> v[i];
            children[v[i]].push_back(i + 1);
        }
        queue<pair<int,int>> q;
        vector<int> dp(n + 1, 0);
        int MOD = 998244353, ans = 1, currlevel = 0, sumcurr = 1, sumprev = 0;
        q.push({1,0});
        while (!q.empty()) {
            int curr = q.front().first, level = q.front().second;
            q.pop();
            if (level != currlevel) {
                sumprev = sumcurr % MOD;
                sumcurr = 0;
                currlevel = (currlevel + 1) % MOD;
            }
            dp[curr] = (sumprev - dp[v[curr - 1]]) % MOD;
            ans = (ans + sumprev - dp[v[curr - 1]]) % MOD;
            sumcurr = (sumcurr + dp[curr]) % MOD;
            for (int i = 0; i < children[curr].size(); i++) {
                q.push({children[curr][i], level + 1});
            }
        }
        cout << (ans + MOD) % MOD << "\n"; // new trick unlocked
    }
}