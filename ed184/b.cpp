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
        string s; cin >> s;
        int n = s.length();
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        int island = -1, ci = 0;
        if (s[0] == '*') {
            island = 0;
            ci++;
        }
        bool inf = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == '*') {
                ci++;
                island = i;
            }
            if (s[i] == '*' && s[i - 1] == '>') {
                inf = true;
                break;
            }
            if (s[i] == '<' && s[i - 1] == '>') {
                inf = true;
                break;
            }
            if (s[i] == '*' && s[i - 1] == '*') {
                inf = true;
                break;
            }
        }
        int idx = -1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '*' && s[i + 1] == '<') {
                inf = true;
                break;
            }
            if (s[i] == '<' && s[i + 1] == '>') {
                idx = i;
            }
        }
        if (inf) {
            cout << "-1\n";
        }
        else {
            if (ci == 1) cout << max(island + 1, n - island) << "\n";
            else if (idx != -1) cout << max(idx + 1, n - (idx + 1)) << "\n";
            else cout << n << "\n";
        }
    }
}