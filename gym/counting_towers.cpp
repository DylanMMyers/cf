#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\counting_towers.exe

ll MOD = 1e9+7;

// NOTES:
// had to delete all previous commentary but, for precomputation don't use function calls as it explodes runtime
// the solution consists of thinking about how we cut the towers,
// for some type one towers we cut it vertically, where the towers are from 0 to n
// for some type two towers, we make a horizontal cut on these vertical towers
// when we make this horizontal cut, we are splitting our towers 4 ways total, so thats why we take 2 and 4 as multiples respectively

// more formally, the type one and two consist of where the nth set of two tiles are either a part of a different block or the same block respectively
// then we consider the previous index, because the current index can have 2 and 4 times the previous index respectively when considering these cuts

// so like, each level adds 2 times as many cuts and 4 times as many cuts when considering both towers
// verbose explnation, but makes sense 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    // pre compute
    vector<vector<ll>> dp(2, vector<ll> (1e6, 0));
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 1; i < 1e6; i++) {
        dp[0][i] = (2 * dp[0][i - 1] + dp[1][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] + 4 * dp[1][i - 1]) % MOD;
    }
    int n;
    while (tt--) {
        cin >> n;
        cout << (dp[0][n - 1] + dp[1][n - 1]) % MOD << "\n";
    }
}