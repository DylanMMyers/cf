#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] > v[maxi]) maxi = i;
        }
        bool same = false;
        for (int i = 1; i < n; i++) {
            if (v[i] != v[i - 1]) break;

            if (i == n - 1) same = true;
        }
        if (same) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (i == maxi) cout << 1;
                else cout << 2;
                cout << " \n"[i == n - 1];
            }
        }
    }
}