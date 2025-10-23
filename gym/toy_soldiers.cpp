#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\toy_soldiers.exe

void solve() {
    // dp for if we buy it or not, what is the cheapest permutation such that we can buy all the figures?
    // can also use some other structure to store some optimal figures?
    // if day is 0, we just carry over maxes, if day is 1, we consider some logic of whether or not we buy a toy at that given step
    // does being greedy in this way work?
    // we can always buy all leftovers on day n

    // can we start from s_n? look backwards for toys that are unattainable at a prev point, then decide if it is beneficial to buy now
    // edge case: add all unbought toys later, if we reach s_0 decide whether or not it is 1/0 and add or don't add price accordingly

    // final idea: prio q, push values which we weren't yet able to buy to prio q, then we can say that once we reach a new time where we can shop we buy this and the top
    // edge case: s_0, buy or not buy?

    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    priority_queue<int> pq;
    // TODO TOMORROW: HOW TO OPTIMIZE PQ?
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) pq.push(i + 1);
        else {
            if (pq.empty()) {
                pq.push(i + 1);
            }
            else {
                ans += pq.top();
                pq.pop();
            }
        }
    }
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";
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