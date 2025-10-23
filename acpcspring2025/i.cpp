#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\i.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n == 2) cout << "Impossible";
        else if (n == 5) {
            cout << "^<==>\n";
            cout << "#<=>^\n";
            cout << "#<=>#\n";
            cout << "v<=>#\n";
            cout << "<==>v\n";
        }
        else if (n % 3 == 0) {
            for (int i = 0; i < n / 3; i++) {
                for (int j = 0; j < n; j++) {
                    cout << '^';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << '#';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << 'v';
                }
                cout << "\n";
            }
        }
        else if (n % 4 == 0) {
            for (int i = 0; i < n / 4; i++) {
                for (int j = 0; j < n; j++) {
                    cout << '^';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << '#';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << '#';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << 'v';
                }
                cout << "\n";
            }
        }
        else {
            int frows = 0, trows = 0, ncopy = n;
            while (ncopy > 0 && !(ncopy % 4 == 0)) {
                trows++;
                ncopy -= 3;
            }
            frows = (n - (3 * trows)) / 4;
            for (int i = 0; i < frows; i++) {
                for (int j = 0; j < n; j++) {
                    cout << '^';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << '#';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << '#';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << 'v';
                }
                cout << "\n";
            }
            for (int i = 0; i < trows; i++) {
                for (int j = 0; j < n; j++) {
                    cout << '^';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << '#';
                }
                cout << "\n";
                for (int j = 0; j < n; j++) {
                    cout << 'v';
                }
                cout << "\n";
            }
        }
    }
}