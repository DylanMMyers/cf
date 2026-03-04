#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe
// g++ a.cpp -o a

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int z = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) z++;
        }
        if (!z) cout << "YES\n";
        else if (k > 1 && z < n) cout << "YES\n";
        else cout << "NO\n";
    }
}