#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe
// g++ file.cpp -o file

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string L, R; cin >> L >> R;

    // dp state is dp[i][j][k][l]
    vector<vector<vector<vector<int>>>> dp(
        vector<vector<vector<int>>>(R.size(), vector<vector<int>>(2, vector<int>(2))));
    for (int i = R.size() - 1; i >= 0; i--) {
        
    }
}