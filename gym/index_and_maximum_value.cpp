#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\index_and_maximum_value.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll maxi = *max_element(v.begin(), v.end());
        for (int i = 0; i < m; i++) {
            char op;
            cin >> op;
            int a, b;
            cin >> a >> b;
            // so for each range, we can just see if there is an element within the range in the vector and increment the max value in this range
            // we can do this because we know that only the max element in the range which is inc/dec will be the answer, otherwise its something else
            if (a <= maxi && b >= maxi) {
                if (op == '+') maxi++;
                else maxi--;
            }
            cout << maxi << " \n"[i == m - 1];
        }
    }
}