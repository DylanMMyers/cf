#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\inter_trees.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (k == 1) {
        cout << 0;
        return 0;
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        c += (s[i] == 'T');
    }
    if (c < k) {
        cout << -1;
        return 0;
    }
    vector<int> idxs;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') continue;
        idxs.push_back(i);
    }
    for (int i = 0; i < idxs.size() - k + 1; i++) {
        int x = idxs[i + k - 1];
        if ((x - idxs[i]) % 2) mini = min(mini, ((x - idxs[i]) / 2) + 1);
        else mini = min(mini, (x - idxs[i]) / 2);
    }
    cout << mini;
}