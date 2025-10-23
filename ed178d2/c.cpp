#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

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
        // if someone has both 1 and n they win
        // edge case for n = 2
        if (n == 2) {
            if (s[0] == 'A') cout << "Alice\n";
            else cout << "Bob\n";
            continue;
        }
        int bob = 0, alice = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') alice++;
            else bob++;
        }
        // conditions
        if (bob > 1 && s[n - 1] == 'B') cout << "Bob\n";
        else if (s[0] == 'B' && s[n - 2] == 'B') cout << "Bob\n";
        else if (s[0] == 'B' && s[n - 1] == 'B') cout << "Bob\n";
        else cout << "Alice\n";
    }
}