#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\engineer_camp.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    // how to impl
    vector<char> ch;
    for (int i = 0; i < 2; i++) {
        for (char j = 'A'; j < 'A' + k; j++) {
            ch.push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.') continue;
            v[i][j] = ch[(j + i) % (k * 2)];
        }
    }
    for (int i = 0; i < n; i++) cout << v[i] << "\n";
}