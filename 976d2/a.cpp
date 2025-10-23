#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, k;
        cin >> n >> k;

        if (k == 1 || k > n) {
            cout << n << endl;
            continue;
        }

        int it = 0;
        long long rem = 1;
        while (rem <= n) {
            rem *= k;
        }
        long long t;
        while (n > 0) {
            t = n / rem;
            it += t;
            n -= rem * t;
            rem /= k;
        }

        cout << it << endl;
    }
}
