#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\b.exe
// g++ b.cpp -o b

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int sum = 0, n = s.length(), ans = 1e9;
        for (int i = 0; i < n; i++) sum += s[i] - '0';
        sort(s.begin() + 1, s.end());
        for (int i = 1; i <= n * 9; i++) {
            string curr = to_string(i);
            int curr_sum = 0, sumc = sum, its = 0;
            for (int j = 0; j < curr.length(); j++) curr_sum += curr[j] - '0';
            if (to_string(curr_sum) != curr) continue;
            bool fuse = false;
            if (curr_sum == sumc) ans = 0;
            else if (sumc < curr_sum) {
                for (int j = 1; j < s.length() && sumc < curr_sum; j++) {
                    if (s[0] < s[j] && s[0] != '1' && !fuse) {
                        its++;
                        sumc = min(curr_sum, sumc + (s[0] - '1'));
                        fuse = true;
                    }
                    if (sumc == curr_sum) break;
                    its++;
                    sumc = min(curr_sum, sumc + (s[j] - '0'));
                }
                if (!fuse && sumc < curr_sum) {
                    sumc = min(curr_sum, sumc + (s[0] - '1'));
                    its++;
                }
                if (sumc == curr_sum) ans = min(ans, its);
            }
            else { // sumc > curr_sum
                for (int j = s.length() - 1; j > 0 && sumc > curr_sum; j--) {
                    if (s[0] > s[j] && s[0] != '1' && !fuse) {
                        its++;
                        sumc = max(curr_sum, sumc - (s[0] - '1'));
                        fuse = true;
                    }
                    if (sumc == curr_sum) break;
                    its++;
                    sumc = max(curr_sum, sumc - (s[j] - '0'));
                }
                if (!fuse && sumc > curr_sum) {
                    sumc = max(curr_sum, sumc - (s[0] - '1'));
                    its++;
                }
                if (sumc == curr_sum) ans = min(ans, its);
            }
        }
        cout << ans << '\n';
    }
}