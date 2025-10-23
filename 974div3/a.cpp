#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int gold = 0, given = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= k) {
                gold += v[i];
            }
            else if (gold > 0 && v[i] == 0) {
                given++;
                gold--;
            }
        }

        cout << given << endl;
    }

    return 0;
}