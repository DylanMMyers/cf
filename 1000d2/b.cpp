#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    l--;
    r--;
    // we can swap or not swap, go from left and right
    // lets select up to  k * 2 (k = r - l + 1) elements from right and left and see 
    // 1 2 3 4 1 1 1, l = 2, r = 3
    // 1 2 1, l = 1, r = 2
    // 1 2 3 4 1, l = 2, r = 4
    ll leftsum = 0, rightsum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= r; i++) {
        pq.push(v[i]);
    }
    for (int i = 0; i < r - l + 1; i++) {
        leftsum += pq.top();
        pq.pop();
    }
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = l; i < n; i++) {
        pq.push(v[i]);
    }
    for (int i = 0; i < r - l + 1; i++) {
        rightsum += pq.top();
        pq.pop();
    }
    
    cout << min(leftsum, rightsum) << "\n";
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