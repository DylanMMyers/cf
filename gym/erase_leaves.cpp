#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\erase_leaves.exe

unordered_map<int,vector<int>> al;

int helper(int curr, int prev) {
    if (al[curr].size() == 1 && al[curr][0] == prev) return 1;

    int c = 1;
    for (int i = 0; i < al[curr].size(); i++) {
        if (al[curr][i] == prev) continue;
        c += helper(al[curr][i], curr);
    }
    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        int maxi = 0;
        for (int i = 0; i < al[1].size(); i++) {
            maxi = max(maxi, helper(al[1][i], 1));
        }
        if (al[1].size() == 1) cout << 1;
        else cout << n - maxi;
    }
}