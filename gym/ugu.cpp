#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\ugu.exe

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
        vector<int> ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + (s[i - 1] - '0');
        }
    }
}