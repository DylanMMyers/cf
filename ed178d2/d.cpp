#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

bool isprime(int n) {
    int cnt = 0;

    if (n <= 1) return false;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cnt++;
    }
    if (cnt > 2) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        sort(v.begin(), v.end());
        // we have a prime every 20 numbers, so 20 * n runtime? lol
        
    }
}