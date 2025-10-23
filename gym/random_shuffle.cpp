#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\random_shuffle.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        random_shuffle(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            cout << v[i] << " \n"[i == n - 1];
        }
    }
}