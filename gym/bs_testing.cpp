#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\bs_testing.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> v(n), queries(q), ps(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < q; i++) cin >> queries[i];
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + v[i - 1];
    // lets just assume at any pos, we have 25 creds and wanna know how many things we can buy
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int low = queries[i], high = n;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (ps[mid] - ps[queries[i] - 1] <= 25) low = mid;
            else high = mid - 1;
        }
        ans[i] = low - (queries[i] - 1);
    }
    for (int x : ans) cout << x << ' ';
}