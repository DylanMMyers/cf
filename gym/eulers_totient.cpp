#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\eulers_totient.exe
// g++ eulers_totient.cpp -o eulers_totient

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> coprime(n + 1);
    for (int i = 0; i <= n; i++) {
        coprime[i] = i;
    }
    for (int i = 2; i < n; i++) {
        if (coprime[i] == i) {
            for (int j = i; j < n; j += i) {
                coprime[j] -= coprime[j] / i;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << i << ": " << coprime[i] << "\n";
    }
}