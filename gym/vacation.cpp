#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\vacation.exe

int memo[1000][1000];

int helper(vector< vector<int> >& v, int idx, int last) {
    if (idx == 0) {
        if (last == 0) memo[0][last] += max(memo[1][1], memo[1][2]); 
        else if (last == 1) memo[0][last] += max(memo[1][2], memo[1][0]); 
        else if (last == 2) memo[0][last] += max(memo[1][1], memo[1][0]); 
    }

    if (memo[idx][last] > 0) return memo[idx][last];

    if (last == 0) memo[idx - 1][last] = v[idx][last] + max(helper(v, idx - 1, 1), helper(v, idx - 1, 2));
    else if (last == 1) memo[idx - 1][last] = v[idx][last] + max(helper(v, idx - 1, 0), helper(v, idx - 1, 2));
    else if (last == 2) memo[idx - 1][last] = v[idx][last] + max(helper(v, idx - 1, 0), helper(v, idx - 1, 1));

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector< vector<int>> v(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }

    memo[0][0] = v[0][0], memo[0][1] = v[0][1], memo[0][2] = v[0][2];

    helper(v, n - 1, 0);
    helper(v, n - 1, 1);
    helper(v, n - 1, 2);

    int maxi = max({memo[n - 1][0], memo[n - 1][1], memo[n - 1][2]});

    cout << maxi;
}