#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\insert_digit.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, d;
        cin >> n >> d;
        string num;
        cin >> num;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(num[i] - '0');
        }
        int idx = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= d) {
                cout << v[i];
                idx++;
            }
            else break;
        }
        cout << d;
        for (int i = idx; i < v.size(); i++) {
            cout << v[i];
        }
        cout << "\n";
    }
}