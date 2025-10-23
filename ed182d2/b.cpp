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
        int n; cin >> n;
        vector<int> v(n + 1); for (int i = 1; i <= n; i++) cin >> v[i];
        set<int> s;
        for (int i = 1; i <= n; i++) {
            if (v[i]) s.insert(v[i]);
        }
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            if (s.find(i) == s.end()) nums.push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            if (!v[i]) {
                v[i] = nums.back();
                nums.pop_back();
            }
        }
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i] != i) {
                a = i;
                break;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (v[i] != i) {
                b = i;
                break;
            }
        }
        if (b != a) cout << b - a + 1 << "\n";
        else cout << "0\n";
    }
}