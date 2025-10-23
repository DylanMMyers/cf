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
        int n; cin >> n;
        vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
        vector<int> ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + v[i - 1];
        }
        bool ans = false;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = ps[i], b = ps[j] - ps[i], c = ps[n] - ps[j];
                a %= 3;
                b %= 3;
                c %= 3;
                if (a > b) swap(a, b);
                if (b > c) swap(b, c);
                if (a > b) swap(a, b);
                if ((a == 0 && b == 1 && c == 2) || (a == b && b == c)) {
                    ans = true;
                    cout << i << ' ' << j << "\n";
                    break;
                } 
            }
            if (ans) break;
        }
        if (!ans) cout << "0 0\n";
    }
}