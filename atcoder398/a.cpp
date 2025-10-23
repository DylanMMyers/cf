#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        if (n == 1) cout << '=';
        else if (n % 2 == 1) {
            for (int i = 0; i < n / 2; i++) {
                s += '-';
            }
            s += '=';
            for (int i = 0; i < n / 2; i++) {
                s += '-';
            }
        }
        else {
            for (int i = 0; i < (n / 2) - 1; i++) {
                s += '-';
            }
            s += '=';
            s += '=';
            for (int i = 0; i < (n / 2) - 1; i++) {
                s += '-';
            }
        }
        cout << s;
    }
}