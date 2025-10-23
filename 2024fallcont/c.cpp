#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 0;
    int r = n - 1;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;

    while (r >= l) {
        if (v[l] == v[r]) {
            l++;
            r--;
        }
        else {
            if (v[l] > v[r]) {
                v[r - 1] += v[r];
                r--;
            }
            else { //v[l] > v[r]
                v[l + 1] += v[l];
                l++;
            }
            ans++;
        }
    }

    cout << ans;

    return 0;
}