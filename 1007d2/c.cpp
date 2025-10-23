#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        int n, st, en;
        cin >> n >> st >> en;
        unordered_map<int,vector<int>> al;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        bool ans = false; // if we're at nth step and our permutation is valid, make this true?
        
    }
}