#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.length() - 2; i++) {
            cout << s[i];
        }
        cout << "i\n";
    }
}