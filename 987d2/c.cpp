    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    // Get-Content t.txt | .\c.exe

    void solve() {
        // from 1 to n, can we fit in some iterations (where the freq >= 2) where the distance is a perfect square
        int n;
        cin >> n;
        // 1 4 9 16 25 36 49 64 81 121 144 169 196 225
        // 16 to 25, 144 to 169
        // at each position, we should try to space elements perfect squares away
        // must be even
        // 1 2 3 4 5 6 7 8 9
        // 1 2 3 4 1 2 3 4
        // 25
        // 16 17 18 19 20 21 22 23 24 25 ############################# 41
        // 1  ####################### 1 ############################## 1
        if (n % 2 == 1) {
            if (n <= 25) {
                cout << -1 << "\n";
                return;
            }
            cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2";
            for (int i = 1; i <= (n - 27) / 2; i++) {
                cout << ' ' << 13 + i << ' ' << 13 + i;
            }
        }
        else {
            cout << 1 << ' ' << 1;
            for (int i = 2; i <= n / 2; i++) {
                cout << ' ' << i << ' ' << i;
            }
        }
        cout << "\n";
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll tt;
        cin >> tt;
        while (tt--) {
            solve();
        }
    }