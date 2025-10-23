#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\c.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll k, x; cin >> k >> x;
        ll c = x, v = (ll)pow(2, k + 1) - c; 
        vector<int> ans;
        while (c != v) {
            if (c > v) {
                c -= v;
                v *= 2;
                ans.push_back(2);
            }
            else {
                v -= c;
                c *= 2;
                ans.push_back(1);
            }
        }
        cout << ans.size() << "\n";
        while (!ans.empty()) {
            cout << ans.back() << ' ';
            ans.pop_back();
        }
        cout << "\n";
    }
}

// key distinction:
// found this approach but from the wrong direction, needed to work backwards
// you tried to do this same approach but from the bottom where we cant make assumptions
// at the end, we can make this assumption
// think about the directions we approach the problem from and what they imply about some operations we can make in general