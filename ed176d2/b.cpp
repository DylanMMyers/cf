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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        // brute force?
        // if we didnt pick k max elements, we would pick the k+1th element which would then land on the kth max element ideally
        // so i think its always optimal to pick the k max elements straight up, then find out what the furthest value is?
        // this works because lets consider x, y, z where x > y > z
        // even if z + y > x, x + y always > y + z
        // this basically means that
        ll ans = 0;
        if (k > 1) {
            priority_queue<pair<int,int>> pq;
            for (int i = 0; i < n; i++) {
                pq.push({v[i], i});
            }
            for (int i = 0; i < k + 1; i++) {
                pair<int,int> top = pq.top();
                pq.pop();
                int x = top.first, y = top.second;
                ans += top.first;
            }
        }
        else {
            int x = v.front(), y = v.back(), curr = 0;
            ans = v.front() + v.back();
            for (int i = 1; i < n - 1; i++) {
                ans = (ll)max({ans, (ll)(v.front() + v[i]), (ll)(v.back() + v[i])});
            }
        }
        cout << ans << "\n";
    }
}