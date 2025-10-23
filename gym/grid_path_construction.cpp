#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\grid_path_construction.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m, y1, x1, y2, x2;
        cin >> n >> m >> y1 >> x1 >> y2 >> x2;
        vector<vector<char>> v(n, vector<char> (m, 'E'));
        if ((max(x1, x2) - min(x1, x2)) == (max(y1, y2) - min(y1, y2))) cout << "NO\n";
        else {
            
        }
    }
}