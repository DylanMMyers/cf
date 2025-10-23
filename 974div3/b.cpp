#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        /*int l = 0;
        for (int i = n - k + 1; i <= n; i++) {
            if (i % 2 == 1) l++;
        }*/
        bool ans = false;
        if ((n - (n - k) + 1) % 2 == 1)  ans = true;
        if (n == 1) cout << "NO" << "\n";
        else if (ans) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}