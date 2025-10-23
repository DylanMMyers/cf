#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve() {
    ll num;
    cin >> num;
    ll it = 0;
    bool found = false;
    vector<int> v;
    while (num > 0) {
        v.push_back(num % 10);
        num /= 10;
    }

    reverse(v.begin(), v.end());
    if (v[v.size() - 1] % 2 == 0) {
        cout << 0 << endl;
        found = true;
    }
    else if (v[0] % 2 == 0) {
        cout << 1 << endl;
        found = true;
    }
    else {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] % 2 == 0) {
                cout << 2 << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) cout << -1 << endl;

}
 
int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}