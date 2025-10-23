#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<int> lis;
        for (int x : a) {
            auto it = upper_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) lis.push_back(x);
            else *it = x;
        }
        cout << lis.size() << '\n';
    }
}