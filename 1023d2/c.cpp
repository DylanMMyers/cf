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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll> v(n);
        ll suma = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            suma += v[i];
        }
        ll forgot = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') forgot++;
        }
        ll currsum = 0, maxsum = -1 * 1e6 - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') currsum = 0;
            else {
                if (currsum + v[i] > 0) {
                    currsum += v[i];
                    maxsum = max(maxsum, currsum);
                }
                else currsum = 0;
            }
        }
        if (maxsum > k) cout << "NO\n";
        else if (maxsum == k) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') cout << v[i];
                else cout << -1e18;
                cout << " \n"[i == n - 1]; 
            }
        }
        else {
            // since our max sub array sum is less than k, lets see if we can bring it up to k
            if (!forgot) cout << "NO\n"; // if we cant change it, ret no
            else {
                (...);
            }
        }
    }
}