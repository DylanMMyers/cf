#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe
// g++ a.cpp -o a

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m, d; cin >> n >> m >> d;
        vector<int> t(n, -1);
        int it = 0, towers = 0;
        while (n > 0) {
            if (t[it] == -1) {
                towers++;
                n--;
                t[it] = 0;
            }
            else if (t[it] + m <= d) {
                n--;
                t[it] += m;
            }
            else {
                it++;
            }
        }
        cout << towers << '\n';
    }
}