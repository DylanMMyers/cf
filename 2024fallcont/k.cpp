#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> ans;

    for (int i = v.size(); i >= 0; i--) {
        if (ans.size() == k) break;
        if (v[i] % 3 == 0) {
            ans.push_back(v[i]);
            if (i - 1 >= 0) {
                if (v[i - 1] + 1 == v[i]) {
                    if (v[i - 1] != -1) ans.push_back(v[i - 1]);
                    v[i - 1] = -1;
                }
            }
            v[i] = -1;
        }
    }

    if (ans.size() < k) {
        int iter = v.size() - 1;
        while (ans.size() < k) {
            if (v[iter] == -1) iter--;
            else {
                ans.push_back(v[iter]);
                iter--;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}