#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        
    }
    vector<long long> ps(n);
    ps[0] = v[0];
    for (int i = 1; i < n; i++) {
        ps[i] += v[i] + ps[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 1) cout << ps[r - 1] << endl;
        else cout << ps[r - 1] - ps[l - 2] << endl;
    }

    return 0;
}