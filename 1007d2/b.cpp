    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    // Get-Content t.txt | .\b.exe

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll tt;
        cin >> tt;
        while (tt--) {
            int n;
            cin >> n;
            if (n == 1) {
                cout << "-1\n";
                continue;
            }
            vector<ll> ans = {2, 1};
            set<ll> s = {1, 8, 49, 288, 1681, 9800, 57121, 332928};
            ll sum = 3;
            for (ll i = 3; i <= n; i++) {
                if (s.find(i) != s.end() && i != n) {
                    ans.push_back(i + 1);
                    ans.push_back(i);
                    sum += 2 * i + 1;
                    i++;
                }
                else {
                    ans.push_back(i);
                    sum += i;
                }
            }
            bool a = true;
            for (ll i = 2; i * i <= sum; i++) {
                if (i * i == sum) a = false;
            }
            if (a) {
                for (int i = 0; i < ans.size(); i++) {
                    cout << ans[i] << " \n"[i == ans.size() - 1];
                }
            }
            else cout << "-1\n";
        }
    }