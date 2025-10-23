#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n == 2) cout << "-1 2\n";
        else {
            bool alter = false;
            for (int i = 0; i < n - 1; i++) {
                if (!alter) cout << "-1 ";
                else cout << "3 ";
                alter = !alter;
            }
            if (n % 2 == 0) cout << "2\n";
            else cout << "-1\n";
        }
    }
}