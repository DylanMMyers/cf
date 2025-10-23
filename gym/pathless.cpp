#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\pathless.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, s; cin >> n >> s;
        vector<int> v(n);
        int ze = 0, on = 0, tw = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ze += v[i] == 0;
            on += v[i] == 1;
            tw += v[i] == 2;
        }
        // if s < sum of v, any arrangement works as alice cant make it to i_n without exceeding s
        int score = accumulate(v.begin(), v.end(), 0);
        if (score > s) {
            for (int i = 0; i < n; i++) {
                cout << v[i] << " \n"[i == n - 1];
            }
        }
        else if (score == s - 1) {
            for (int i = 0; i < ze; i++) {
                cout << "0 ";
            }
            for (int i = 0; i < tw; i++) {
                cout << "2 ";
            }
            for (int i = 0; i < on; i++) {
                cout << 1 << " \n"[i == on - 1];
            }
        }
        else cout << "-1\n";
    }
}