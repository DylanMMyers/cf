#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

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
        for (int i = 0; i < n - 1; i++) {
            // logic...
            // use current (asumleft + xsumleft * new units) compared to (asumright + xsumright * new units) to determine where to place new units for each turn
            // divide or subtract from xsum and asum respectively using xs and as, helps track most optimal route as we go
            // then we update the next tile with the newly placed units and our ans will be final two values added, by when we start from 0 we place 1s at 0,0 and do the first operations
            ll x = ans[0][i], y = ans[1][i]; // x == left, y == right
            ans[0][i + 1] = x;
            ans[1][i + 1] = y;
            ll cl = 0, cr = 0;

            if (xs[0][i] == 1) cl = as[0][i];
            else cl = x * (xs[0][i] - 1) + (y * xs[0][i] - 1);
            if (xs[1][i] == 1) cr = as[1][i];   
            else cr = y * (xs[1][i] - 1) + x * (xs[1][i] - 1);

            for (int j = i + 1; j < n; j++) {
                cl += as[0][j] + (cl * (xs[0][j] - 1));
                cr += as[1][j] + (cr * (xs[1][j] - 1));
            }
            cout << "YERD\n";
            if (cl > cr) ans[0][i + 1] += (as[0][i] + (x * (xs[0][i] - 1))) + (as[1][i] + (y * (xs[1][i] - 1)));
            else ans[1][i + 1] += (as[0][i] + (x * (xs[0][i] - 1))) + (as[1][i] + (y * (xs[1][i] - 1)));
        }
        cout << as[0][n - 1] + (ans[0][n - 1] * xs[0][n - 1]) + as[1][n - 1] + (ans[1][n - 1] * xs[1][n - 1]) << "\n";
        //cout << 1 << "\n";
    }
}