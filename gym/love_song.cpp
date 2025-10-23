#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\love_song.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + (s[i - 1] - 'a' + 1);
        }    
        int l, r;
        for (int i = 0; i < q; i++) {
            cin >> l >> r;
            cout << ps[r] - ps[l - 1] << "\n";
        }
    }
}