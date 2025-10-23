#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\goin_to_the_zoo.exe

void check(vector<int>& visits, ll& ans, vector<vector<int>>& k, vector<int>& c) {
    ll cost = 0, n = visits.size(), m = k[0].size();
    vector<int> animals(m, 0);
    for (int i = 0; i < n; i++) {
        cost += visits[i] * c[i];
        for (int j = 0; j < m; j++) {
            animals[j] += visits[i] * k[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        if (animals[i] < 2) return;
    }
    ans = min(ans, cost);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> c(n);
        vector<vector<int>> k(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            for (int j = 0; j < a; j++) {
                int b;
                cin >> b;
                k[b - 1][i]++;
            }
        }
        // brute force it?
        // yes we can brute force
        // observation is: can visit each zoo no more than 3 times so lets consider visiting each zoo 0 <= v <= 2 times (3^n)
        // then check in n*m per case so time is fine
        ll ans = LLONG_MAX, total = 1;
        for (int i = 0; i < n; i++) {
            total *= 3;
        }
        vector<int> visits(n);
        for (int mask = 0; mask < total; mask++) {
            int x = mask;
            for (int i = n - 1; i >= 0; i--) {
                visits[i] = x % 3; 
                x /= 3;
            }
            check(visits, ans, k, c);
        }
        cout << ans;
    }
}