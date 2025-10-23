#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector<int> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }
        vector<int> idx;
        for (int i = 0; i < m - 1; i++) {
            if (v[i] + 1 < v[i + 1]) idx.push_back(v[i] + 1);
        }
        idx.push_back(v.back() + 1);
        int curr = 1;
        char prev = 'A';
        vector<int> res = {2};
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                if (prev == 'B') {
                    curr++;
                    auto ita = lower_bound(v.begin(), v.end(), curr);
                    if (ita != v.end()) {
                        if (*ita == curr) {
                            ita = lower_bound(idx.begin(), idx.end(), curr);
                            if (ita != idx.end()) curr = *ita;
                            else curr++;
                        }
                    }
                }
                curr++;
                prev = 'A';
            }
            else { // B
                if (prev == 'B') {
                    curr++;
                    auto ita = lower_bound(v.begin(), v.end(), curr);
                    if (ita != v.end()) {
                        if (*ita == curr) {
                            ita = lower_bound(idx.begin(), idx.end(), curr);
                            if (ita != idx.end()) curr = *ita;
                            else curr++;
                        }
                    }
                }
                auto it = lower_bound(v.begin(), v.end(), curr + 1);
                if (it != v.end()) {
                    if (*it == curr + 1) {
                        it = lower_bound(idx.begin(), idx.end(), curr + 1);
                        if (it == idx.end()) curr++;
                        else curr = *it;
                    }
                    else curr++;
                }
                else curr++;
                prev = 'B';
            }
            res.push_back(curr);
        }
        set<int> st;
        for (int i = 0; i < m; i++) st.insert(v[i]);
        for (int i = 0; i < res.size(); i++) st.insert(res[i]);
        cout << st.size() << "\n";
        for (int x : st) cout << x << ' ';
        cout << "\n";
    }
}