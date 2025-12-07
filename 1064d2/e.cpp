#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\e.exe
// g++ e.cpp -o e

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<vector<pair<int,int>>> bitcost(31, vector<pair<int,int>>);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                int curr = 1 << j;
                if (v[i] < curr) {
                    bitcost.push_back({curr - v[i], i});
                }
                else bitcost.push_back({0, i});
            }
        }
        
    }
}