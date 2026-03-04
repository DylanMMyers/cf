#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe
// g++ d.cpp -o d

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        // can choose 2 paths from any node and go down them as many times
        // edge case if we have a snake graph or splits later than one
        ll n, k; cin >> n >> k;
        vector<vector<int>> al(n);
        for (int i = 0; i < n - 1; i++) {
            int p; cin >> p;
            p--;
            al[p].push_back(i);
        }
        vector<ll> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        function<ll(int, ll)> dfs = [&](int node, ll weight) {
            if (al[node].size()) return weight * s[node];
            
            // want to determine order in which child nodes deserve more flow
            ll base = weight / al[node].size(), rem = weight % al[node].size();
            vector<vector<ll>> diffs(al[node].size()); // diffs[i] = {score diff with +1, base score, node}
            for (int i = 0; i < al[node].size(); i++) {
                ll curro = dfs(al[node][i], base + 1), currz = dfs(al[node][i], base);
                diffs[i] = {curro - currz, currz, al[node][i]}; 
            }
            sort(diffs.begin(), diffs.end());
            ll local = 0;
            for (int i = 0; i < rem; i++) {
                local += diffs[i][0] + diffs[i][1];
            }
            for (int i = rem; i < al[node].size(); i++) {
                local += diffs[i][1];
            }
            return local;
        };
        ll ans = dfs(0, k);
        cout << ans << '\n';
    }
}