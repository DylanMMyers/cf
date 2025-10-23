    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    // Get-Content t.txt | .\d.exe

    void solve() {
        ll n, m, L;
        cin >> n >> m >> L;
        vector<ll> l(n);
        vector<ll> r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }
        vector<ll> p(m);
        vector<ll> v(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i] >> v[i];
        }
        // we can select any index n -> n + k where k is jump power, therefore:
        // we need just enough jump power before each hurdle, and if we can't obtain this we return -1
        ll k = 1, num = 0, iter = 0;
        priority_queue<ll> pq;
        for (int i = 0; i < n; i++) {
            for (int j = iter; j < m; j++) {
                if (p[j] >= l[i]) break;
                pq.push(v[j]);
                iter++;
            }
            if (k < r[i] - l[i] + 2) {
                while (!pq.empty() && k < r[i] - l[i] + 2) {
                    k += pq.top();
                    pq.pop();
                    num++;
                }
                if (pq.empty() && k < r[i] - l[i] + 2) {
                    cout << -1 << "\n";
                    return;
                }
            }
        }
        cout << num << "\n";
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll tt;
        cin >> tt;
        while (tt--) {
            solve();
        }
    }