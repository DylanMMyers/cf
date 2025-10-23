#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        long long k;
        cin >> k;

        // 1 2 3 4 5
        // 0 0 0 0 0
        // 0 1 0 1 0
        // 0 1 1 1 0
        // 0 1 1 0 0
        // 0 1 1 0 1

        int count = 1;
        for (int i = 2; i < k; i++) {
            if (i * i <= k + i) count++;
        }

        // 1 2 3 4 5 6
        // 0 0 0 0 0 0
        // 0 1 0 1 0 1
        // 0 1 1 1 0 1
        // 0 1 1 1 1 1
        // 0 1 1 1 1 0

        cout << k + count << endl;
    }
}