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
        int n;
        cin >> n;
        vector<int> v(n);
        int mini;
        cin >> v[0];
        if (v[0] < 0) v[0] *= -1;
        mini = v[0];
        for (int i = 1; i < n; i++) {
            cin >> v[i];
            if (v[i] < 0) v[i] *= -1;
        }
        // ok so median of odd count is n / 2 th element
        // median of even count is n / 2 - 1 th element
        // can start by converting all elements to even
        // then if we have enough elements on either side it can be done
        // only time it cant be done is if our element is an extrema on both sides, so if when everything is even we dont have 
        sort(v.begin(), v.end());
        // for (int i = 0; i < n; i++) {
        //     cout << v[i] << " \n"[i == n - 1];
        // }
        // so essentially, the abs value of the number at the first index must already be <= the median position, if so then YES
        // otherwise NO
        bool seen = false;
        for (int i = 0; i < (n / 2) + 1; i++) {
            if (v[i] == mini) seen = true;
        }
        if (seen) cout << "YES\n";
        else cout << "NO\n";
    }
}