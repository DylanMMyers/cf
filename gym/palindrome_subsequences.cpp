#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\palindrome_subsequences.exe
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 1);
    // N = 6 IS THE ONLY EDGE CASE
    if (n == 6) {
        vector<int> v = {1, 1, 2, 3, 1, 2};
        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << "\n";
        return;
    }
 
    for (int i = 0; i < n - 2; i++) {
        v[i] = i + 1;
    }
    v[n - 2] = 1;
    v[n - 1] = 2;
    
 
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}