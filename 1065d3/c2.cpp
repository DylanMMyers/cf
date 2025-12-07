#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c2.exe
// g++ c2.cpp -o c2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int tot = 0;
        for (int i = 0; i < n; i++) tot ^= a[i];
        for (int i = 0; i < n; i++) tot ^= b[i];
        int msb = 0;
        for (int i = 25; i >= 0; i--) {
            if ((1 << i) & tot) {
                msb = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) a[i] = (a[i] & (1 << msb) ? 1 : 0);
        for (int i = 0; i < n; i++) b[i] = (b[i] & (1 << msb) ? 1 : 0);
        int aji = 0, mai = 0;
        for (int i = 0; i < n; i++) aji += a[i] == 1;
        for (int i = 0; i < n; i++) mai += b[i] == 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            if (!(i % 2)) {
                // aji
                if (!(aji % 2) && a[i] == 0 && b[i] == 1) {
                    aji++;
                    mai--;
                }
                else if (!(aji % 2) && a[i] == 1 && b[i] == 0) {
                    aji--;
                    mai++;
                }
            }
            else {
                // mai
                if (!(mai % 2) && b[i] == 0 && a[i] == 1) {
                    mai++;
                    aji--;
                }
                else if (!(mai % 2) && b[i] == 1 && a[i] == 0) {
                    mai--;
                    aji++;
                }
            }
        }
        if (mai % 2 == aji % 2) cout << "Tie\n";
        else if (mai % 2 == 1) cout << "Mai\n";
        else cout << "Ajisai\n";
    }
}