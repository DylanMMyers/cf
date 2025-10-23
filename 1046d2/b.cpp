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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> ans(n);
        int oc = 0;
        for (int i = 0; i < n; i++) oc += s[i] == '1';
        int winc = 0, low = 1, high = n;
        bool flag = true;
        for (int i = 0; i < k; i++) {
            if (s[i] == '1') {
                winc++;
                ans[i] = low;
                low++;
            }
            else {
                ans[i] = high;
                high--;
            }
        }
        if (winc == k) flag = false;
        for (int i = k; i < n; i++) {
            winc -= (s[i - k] == '1');
            if (s[i] == '1') {
                winc++;
                ans[i] = low;
                low++;
            }
            else {
                ans[i] = high;
                high--;
            }
            if (winc == k) {
                flag = false;
                break;
            }
        }
        if (!flag) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
        }
    }
}