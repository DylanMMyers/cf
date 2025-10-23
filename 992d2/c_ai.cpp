#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c_ai.exe

// Function to compute factorials up to n
vector<ll> computeFactorials(int n) {
    vector<ll> fact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        if (fact[i] > 1e12) { // Cap factorials to avoid overflow for large k
            fact[i] = 1e12 + 1;
        }
    }
    return fact;
}

// Function to solve a single test case
void solve() {
    int n;
    ll k;
    cin >> n >> k;

    // Precompute factorials up to the maximum possible n
    static const int MAX_N = 200000;
    static vector<ll> fact = computeFactorials(MAX_N);

    // Check if there are fewer than k permutations
    if (k > fact[n]) {
        cout << -1 << endl;
        return;
    }

    // Generate the k-th permutation in lexicographical order
    vector<int> nums(n);
    for (int i = 0; i < n; i++) nums[i] = i + 1;

    vector<int> result;
    k--; // Convert to zero-based index

    for (int i = 0; i < n; i++) {
        int blockSize = fact[n - 1 - i];
        int index = k / blockSize; // Determine the index in the current block
        result.push_back(nums[index]);
        nums.erase(nums.begin() + index); // Remove used number
        k %= blockSize; // Update k for the next iteration
    }

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}