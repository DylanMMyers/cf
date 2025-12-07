#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        int z = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (!v[i]) z++;
        }
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        sort(v.rbegin(), v.rend());
        int r = n - z;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
        }
        int l = r, it = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (!v[i]) continue;
            it++;
            if ((sum - it) / (n - 1) > 0) l = i + 1;
        }
        cout << r - l + 1 << "\n";
    }
}