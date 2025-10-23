#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\love_triangle.exe

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
        bool ans = false;
        int a = -1, b = -1, c = -1;
        for (int i = 0; i < n; i++) {
            a = v[i] - 1;
            b = v[a] - 1;
            c = v[b] - 1;
            if (c == i) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES" : "NO");
    }
}