#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\merge_sort.exe

vector<int> mergeSort(vector<int> v) {
    if (!v.size()) return {};
    if (v.size() == 1) return v;
    vector<int> a, b;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    a = mergeSort(a);
    b = mergeSort(b);
    vector<int> res;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (x == a.size()) {
            res.push_back(b[y]);
            y++;
            continue;
        }
        if (y == b.size()) {
            res.push_back(a[x]);
            x++;
            continue;
        }

        if (a[x] < b[y]) {
            res.push_back(a[x]);
            x++;
        }
        else {
            res.push_back(b[y]);
            y++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> ans = mergeSort(v);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
}