#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long p = 1;
    long long ans = 0;
    n--;
    while (p < k) {
        n -= p;
        p *= 2;
        ans++;
    }
    p = k;

    while (n > 0) {
        n -= p;
        ans++;
    }

    cout << ans;

    return 0;
}