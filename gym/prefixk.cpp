#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<long long> ps(n);
        ps[0] = v[0];
        for (int i = 1; i < n; i++) {
            ps[i] = v[i] + ps[i - 1];
        }

        for (int i = 0; i < q; i++) {
            long long l, r, k;
            cin >> l >> r >> k;
            long long curr = ps[n - 1];
            if (l == 1) curr -= ps[r - 1];
            else curr -= ps[r - 1] - ps[l - 2];
            curr += (k * (r - l + 1));
            if (curr % 2 == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}