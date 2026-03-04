#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d1.exe
// g++ d1.cpp -o d1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        // must remove two at a time
        int maxi = -1;
        vector<int> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + (s[i] == '(');
        }
        bool ok = false;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == '(' || s[i + 1] == ')' || suf[i + 2] < 1) continue;

            ok = true;
            break;
        }
        cout << (ok ? n - 2 : -1) << '\n';
    }
}