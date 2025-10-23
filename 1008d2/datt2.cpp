#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\datt2.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        // 0 == +, 1 == *
        // 0 is left, 1 is right
        vector<vector<int>> op(2, vector<int>(n, 0));
        vector<vector<ll>> xs(2, vector<ll>(n, 1));
        vector<vector<ll>> as(2, vector<ll>(n, 0));
        vector<vector<ll>> ans(2, vector<ll>(n, 0));
        ans[0][0] = 1;
        ans[1][0] = 1;
        for (int i = 0; i < n; i++) {
            char op1, op2;
            int x, y;
            cin >> op1 >> x >> op2 >> y;
            if (op1 == '+') as[0][i] = x;
            else xs[0][i] = x;
            if (op2 == '+') as[1][i] = y;
            else xs[1][i] = y;
        }
        ll l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            // left logic
            l *= xs[0][i];
            l += as[0][i] + as[1][i] + xs[1][i] - 1;
        }
        for (int i = 0; i < n; i++) {
            // right logic
            r *= xs[1][i];
            r += as[0][i] + as[1][i] + xs[0][i] - 1;
        }
        cout << max(1 + l, 1 + r) << "\n";
    }
}