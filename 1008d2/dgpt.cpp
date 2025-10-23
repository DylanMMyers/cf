#include <bits/stdc++.h>
using namespace std;
// Get-Content t.txt | .\dgpt.exe

void solve() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of gate pairs

        vector<pair<string, int>> leftGates(n), rightGates(n);
        for (int i = 0; i < n; ++i) {
            cin >> leftGates[i].first >> leftGates[i].second;
            cin >> rightGates[i].first >> rightGates[i].second;
        }

        // DP table: dp[l][r] stores max total after processing some gates
        map<pair<int, int>, int> dp;
        dp[{1, 1}] = 2; // Initially, 1 person in each lane

        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> newDp;

            for (auto &[state, total] : dp) {
                int leftLane = state.first;
                int rightLane = state.second;

                // Calculate gains from current pair of gates
                int leftGain = 0, rightGain = 0;

                if (leftGates[i].first == "+") {
                    leftGain = leftGates[i].second;
                } else if (leftGates[i].first == "x") {
                    leftGain = (leftGates[i].second - 1) * leftLane;
                }

                if (rightGates[i].first == "+") {
                    rightGain = rightGates[i].second;
                } else if (rightGates[i].first == "x") {
                    rightGain = (rightGates[i].second - 1) * rightLane;
                }

                // Try all possible allocations of gains
                for (int allocateToLeft = 0; allocateToLeft <= leftGain + rightGain; ++allocateToLeft) {
                    int newLeftLane = leftLane + allocateToLeft;
                    int newRightLane = rightLane + (leftGain + rightGain - allocateToLeft);

                    newDp[{newLeftLane, newRightLane}] =
                        max(newDp[{newLeftLane, newRightLane}], total + leftGain + rightGain);
                }
            }

            dp = move(newDp); // Update DP table
        }

        // Find maximum total in DP table
        int maxTotal = 0;
        for (auto &[state, total] : dp) {
            maxTotal = max(maxTotal, total);
        }

        cout << maxTotal << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
