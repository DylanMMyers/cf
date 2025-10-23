#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<int> bitc(31, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                if ((1 << j) & v[i]) bitc[j]++;
            }
        }
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({v[i], i});
        }
        ll stones = 0, piles = 0;
        while (!pq.empty()) {
            int x = pq.top().first, idx = pq.top().second;
            pq.pop();
            bool valid = true;
            for (int i = 0; i < 31; i++) {
                if ((1 << i) & x && bitc[i] <= 1) {
                    valid = false;
                    x -= (1 << i);
                }
            }
            if (!valid) {
                pq.push({x, idx});
                continue;
            }
            // x represents the min the element can be, not the score we get from removing it
            stones += v[idx] - x;
            piles++;
        }
        if (piles % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
// from current pos, if no way to make it to where the next person has forced even parity, you lose
// forced moves vs moves, parity of these
// 1 1 1 1 1
// 