#include <bits/stdc++.h>
#define ll long long
using namespace std;
// g++ train.cpp -o train
// Get-Content t.txt | .\train.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l, p; cin >> n >> l >> p;
    int maxi = 0;
    int fur = (n * l) - (l / 2);
    vector<int> v(n, 0);
    for (int i = 0; i < p; i++) {
        int x; cin >> x;
        int d = max((x % l) - (l / 2), (l / 2) - (x % l));
        if (x >= fur) {
            v[n - 1]++;
            maxi = max(maxi, x - fur);
        }
        else v[x / l]++;
        maxi = max(maxi, d);
    }
    cout << maxi << "\n";
    cout << *max_element(v.begin(), v.end());
}