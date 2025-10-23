#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve() {
    ll A, B;
    cin >> A >> B;
    vector<int> v;
    ll mini = min(A, B), maxi = max(A, B);
    ll sq = sqrt(mini);
    for (int i = 1; i <= sq; i++) {
        if (mini % i == 0) v.push_back(i);
    }
    sq = v.size();
    for (int i = 0; i < sq; i++) {
        if (v[i] * v[i] != mini) v.push_back(mini / v[i]);
    }
    sort(v.rbegin(), v.rend());
    sq = v.size();
    ll lcm, hcf;
    for (int i = 0; i < sq; i++) {
        if (maxi % v[i] == 0) {
            hcf = v[i];
            break;
        }
    }
    lcm = (A * B) / hcf;

    cout << lcm << ' ' << hcf << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}