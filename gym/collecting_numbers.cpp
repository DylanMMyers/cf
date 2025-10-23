#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\collecting_numbers.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        pos[v[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] < pos[i - 1]) ans++;
    }
    cout << ans;
}