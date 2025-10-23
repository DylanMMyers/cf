#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\removing_digits.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> curr, dp(n + 1, 1e6 + 1);
    dp.back() = 0;
    int k;
    for (int i = n; i > 0; i--) {
        if (dp[i] > 1e6) continue;
        k = i;
        while (k > 9) {
            curr.push_back(k % 10);
            k /= 10;
        }
        curr.push_back(k);
        k = curr.size();
        for (int j = 0; j < k; j++) {
            if (i - curr[j] >= 0) dp[i - curr[j]] = min(dp[i] + 1, dp[i - curr[j]]);
        }
        curr.clear();
    }
    cout << dp[0] << "\n";
}