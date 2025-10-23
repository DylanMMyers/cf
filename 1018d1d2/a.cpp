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
        string s;
        cin >> s;
        vector<int> v(n);
        int it = n - 2, len = 1;
        while (it >= 0) {
            if (s[it] == '>') {
                it--;
                continue;
            }
            v[it + 1] = len;
            len++;
            it--;
        }
        it = 0;
        v[0] = len;
        len++;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '>') {
                v[i + 1] = len;
                len++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << v[i] << " \n"[i == n - 1];
        }
    }
}