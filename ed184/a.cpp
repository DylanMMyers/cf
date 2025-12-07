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
        int n, a; cin >> n >> a;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] < a) x++;
            else if (v[i] > a) y++;
        }
        if (x > y) cout << a - 1;
        else cout << a + 1;
        cout << "\n";
    }
}