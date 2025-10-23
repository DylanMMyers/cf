#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\array_description.exe

int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // every time we come across a new unknown value, don't we create UP TO 3x the amount of branches?
    // 5 0 3, we have only one option, a_2 = 4
    // but for something like 3 0 3 we can have : 3 2 3, 3 3 3, 3 4 3
    // so we need to somehow define what a 0 can be, and relate this to how many combinations it creates
    // what if we have like 3 0 0 0 3 vs 3 0 0 0 4 vs 3 0 0 0 5 vs 3 0 0 0 7
    // so for each possibility, we can consider the values that are |1| away and then discard invalid numbers?

    // for 3 0 3, we have: 3 2 3, 3 3 3, 3 4 3
    // for 3 0 0 3, we have: 3 2 2 3, 3 2 3 3, 3 3 2 3, 3 3 3 3, 3 3 4 3, 3 4 3 3, 3 4 4 3
    // for 3 0 0 4, we have: 3 2 3 4, 3 3 3 4, 3 3 4 4, 3 4 3 4, 3 4 4 4, 3 4 5 4

    // for each number, we have the sum of 3 + (amount of 0s in between - 1), so like 3 + 4 + ... 3 + (zcount_1 - 1)
    // then for the cap, how does this effect our problem?
    // for 3 0 3 and 3 0 0 3, what does cap = 3 do?
    // 3 0 3 : 3 2 3, 3 3 3 (minus 1)
    // 3 0 0 3 : 3 2 2 3, 3 2 3 3, 3 3 2 3, 3 3 3 3 (minus 3)
    // so for every element that is affected by the cap, it is the same behavior except it loses sum of (capcount_i - 1) so like 1 + 2 + ... + capcount_i

    // or am i just stupid and we can dfs the amount of valid numbers at a given a_i and then multiply as we go through
    
    vector<vector<int>> dp(n, vector<int> (m + 1, 0));
    if (!v[0]) {
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 1;
        }
    }
    else dp[0][v[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (!v[i]) {
            for (int j = 1; j <= m; j++) {
                for (int k = j - 1; k <= j + 1; k++) {
                    if (k > 0 && k <= m) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD; // if curr is 0, we can use any value that satisfies a previous value/set, and where its not below 1 or greater than m
                    // so we iterate through all values and add these accordingly
                }
            }
        }
        else {
            for (int k = v[i] - 1; k <= v[i] + 1; k++) {
                if (k > 0 && k <= m) dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][k]) % MOD; // otherwise if it isnt, we are more limited and must select from only values from before which satisfy the |1| req
                // then we just ignore all other calculations, making it an efficient O(n * m)
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n - 1][i]) % MOD; // then we add all values from the final row as they represent all combinations from beginning to end
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
}