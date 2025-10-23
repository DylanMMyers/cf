#include <bits/stdc++.h>

using namespace std;

int change(int amount, vector<int>& coins) {
    if (amount == 0) return 1;

    int n = coins.size();
    sort(coins.begin(), coins.end());
    vector<int> dp(1 + coins.back() + amount, 0);

    dp[0] = 1;

    for (int i = 0; i < amount; i++) {
        if (dp[i] > 0) {
            for (int j = 0; j < n; j++) {
                dp[i + coins[j]] += dp[i];
            }
        }
    }

    return dp[amount];
}

int main() {
    vector<int> v = {1, 2, 5};
    cout << change(5, v);
}