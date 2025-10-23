#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int l = -1, r = n - 1, mid;
        while (l != r) {
            mid = (l + r + 1) / 2;
            if (v[mid] < a) l = mid;
            else r = mid - 1;
        }
        int l2 = -1, r2 = n - 1, mid2;
        while (l2 != r2) {
            mid2 = (l2 + r2 + 1) / 2;
            if (v[mid2] <= b) l2 = mid2;
            else r2 = mid2 - 1;
        }
        cout << l2 - l << endl;
    }
}