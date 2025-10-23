#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (b > c) swap(b, c);
        vector<int> v;
        for (int i = 1; i * i <= b * c; i++) {
            if ((b * c) % i == 0) {
                v.push_back(i);
                v.push_back((b * c) / i);
            }
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (!(v[i] % b) && !(v[i] % c)) {
                mini = min(a + v[i], mini);
            }
        }
    }
    cout << mini;
}