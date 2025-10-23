#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l = -1, r = n - 1, k, mid = (l + r) / 2;
        cin >> k;
        while (l != r) {
            if (v[mid] <= k) l = mid;
            else r = mid - 1;
            mid = (r + l + 1) / 2;
        }
        cout << l + 1 << endl;
    }
}