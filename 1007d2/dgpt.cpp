#include <iostream>
#include <vector>
using namespace std;

// Function to compute cumulative XOR up to index i
int cumulativeXOR(int i, const vector<int>& prefixXOR) {
    return prefixXOR[i];
}

// Function to compute value at position l efficiently
int computeValue(long long l, int n, const vector<int>& prefixXOR) {
    while (l > n) {
        l /= 2;  // Move to parent index
    }
    return cumulativeXOR(l - 1, prefixXOR);  // Return corresponding value (0-based index)
}

void solve() {
    int t;  // Number of test cases
    cin >> t;

    while (t--) {
        long long n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        vector<int> prefixXOR(n);

        // Read first n elements of the sequence
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            prefixXOR[i] = (i == 0 ? a[i] : prefixXOR[i - 1] ^ a[i]);
        }

        // Since l == r, we only need to compute value at position l
        cout << computeValue(l, n, prefixXOR) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}