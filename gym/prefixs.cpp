#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<long long> v(n - 1);
    vector<long long> ps(n, 0);

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            v[i] = 1;
        }
    }

    ps[0] = 0;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] == 1) ps[i]++;
        ps[i] += ps[i - 1];
    }

    for (int i = 0; i < q; i++) {
        long long l, r;
        cin >> l >> r;
        cout << ps[r - 1] - ps[l - 1] << endl;
    }
    return 0;
}