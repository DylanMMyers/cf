#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\takahashi_quest.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        unordered_map<int,vector<int>> mp;
        bool f = true;
        vector<int> v(n, -1), beg(n, 0);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 1) mp[y].push_back(i);
            else v[i] = y;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == -1) continue;
            
            if (mp[v[i]].size() > 0) {
                beg[mp[v[i]].back()] = 1;
                beg[i] = -1;
                mp[v[i]].pop_back();
            }
            else {
                f = false;
                break;
            }
        }
        int c = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            c += beg[i];
            ans = max(c, ans);
        }
        if (f) {
            cout << ans << "\n";
            for (int i = 0; i < n; i++) {
                if (beg[i] == -1) continue;
                cout << beg[i] << ' ';
            }
        }
        else cout << -1;
    }
}