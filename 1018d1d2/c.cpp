#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<vector<int>> v(n, vector<int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        // if the same h occurs above or below, increase row (hire a)
        // if the same h occurs on left or right, increase column (hire b)
        // if both, increase row and column (hire a and b)
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool hirea = false, hireb = false;
                if (i > 0) {
                    if (v[i - 1][j] == v[i][j]) hirea = true;
                }
                if (j > 0) {
                    if (v[i][j - 1] == v[i][j]) hireb = true;
                }
                if (hirea && (a[i] != -1)) {
                    cost += a[i];
                    a[i] = -1;
                    for (int k = 0; k < n; k++) {
                        v[i][k]++;
                    }
                }
                if (hireb && (b[j] != -1)) {
                    cost += b[j];
                    b[j] = -1;
                    for (int k = 0; k < n; k++) {
                        v[k][j]++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool hirea = false, hireb = false;
                if (i > 0) {
                    if (v[i - 1][j] == v[i][j]) hirea = true;
                }
                if (j > 0) {
                    if (v[i][j - 1] == v[i][j]) hireb = true;
                }
                if (hirea && (a[i] != -1)) {
                    cost += a[i];
                    a[i] = -1;
                    for (int k = 0; k < n; k++) {
                        v[i][k]++;
                    }
                }
                if (hireb && (b[j] != -1)) {
                    cost += b[j];
                    b[j] = -1;
                    for (int k = 0; k < n; k++) {
                        v[k][j]++;
                    }
                }
            }
        }
        bool f = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    if (v[i - 1][j] == v[i][j]) f = false;
                }
                if (i < n - 1) {
                    if (v[i + 1][j] == v[i][j]) f = false;
                }
                if (j > 0) {
                    if (v[i][j - 1] == v[i][j]) f = false;
                }
                if (j < n - 1) {
                    if (v[i][j + 1] == v[i][j]) f = false;
                }
            }
        }
        if (f) cout << cost << "\n";
        else cout << "-1\n";
    }
}