#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        ll suma = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            suma += v[i];
        }
        // so if its odd, tom wins by default
        // if even, jerry wins by default
        // then we have to solve max(v) - min(v) > k case to determine if game ends sooner
        // aka can the destined winner throw the match
        bool t = false; // true = tom, false = jerry
        if (suma % 2 == 1) t = true;

        // logic for k case
        // so for this case, it should either already be true at the start or avoidable
        // lets say we have k = 2 and only elements 3 1, tom or jerry regardless of turn can always just change it to 2 1 so, and there is no way to sabotage
        // so then, we can just check if the current arrangement (the init) of the array possesses a scenario where a_i - a_j > k + 1 and ret based on this
        int maxi = 0, mini = 1e9 + 1;
        for (int i = 0; i < n; i++) {
            if (v[i] > v[maxi]) maxi = i;
        }
        v[maxi]--;
        maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
            mini = min(mini, v[i]);
        }
        if (maxi - mini > k) cout << "Jerry\n";
        else cout << (t ? "Tom\n" : "Jerry\n");
    }
}