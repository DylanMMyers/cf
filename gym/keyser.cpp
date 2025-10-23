#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\keyser.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> e, o;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2) o.push_back(x);
        else e.push_back(x);
    }
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    for (int i = 0; i < e.size(); i++) {
        if (!k) break;
        k--;
        cout << e[i] << " \n"[!k];
    }
    if (!k) return 0;
    for (int i = o.size() - 1; i >= 0; i--) {
        if (!k) break;
        k--;
        cout << o[i] << " \n"[!k];
    }
}

// 0 100%
// 1 50%
// 2 75%
// 3 62.5%
// 4 68.75%