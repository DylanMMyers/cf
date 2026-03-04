#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) v.push_back(1);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) v.push_back(0);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] != 1 && a[i] != 0) v.push_back(a[i]);
        }
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            set<int> mexfs, mexbs;
            int mexf = 0, mexb = 0;
            for (int j = 0; j < i + 1; j++) {
                mexfs.insert(v[j]); 
            }
            for (int j = i + 1; j < n; j++) {
                mexbs.insert(v[j]);
            }
            for (int x : mexfs) {
                if (x == mexf) mexf++;
            }
            for (int x : mexbs) {
                if (x == mexb) mexb++;
            }
            if (mexf == mexb) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}