#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\saraga.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    // start from the front of s and the back of t
    // find the first common letter that isn't the last or first letter and thats the answer
    unordered_map<char, int> mp;
    // mark the first occuring index of the letter from the back that isn't the last letter, then search from front of S
    // 2 * n
    for (int i = t.size() - 2; i >= 0; i--) {
        if (mp.find(t[i]) == mp.end()) mp[t[i]] = t.size() - i - 1;
    }
    int size = INT_MAX, l, r;
    for (int i = 1; i < s.size(); i++) {
        if (mp.find(s[i]) == mp.end()) continue;

        if (i + mp[s[i]] < size) {
            l = i;
            r = t.size() - mp[s[i]];
            size = l + mp[s[i]];
        }
    }
    if (size == INT_MAX) {
        cout << -1;
        return 0;
    }
    string ans = "";
    for (int i = 0; i <= l; i++) {
        ans += s[i];
    }
    for (int i = r; i < t.size(); i++) {
        ans += t[i];
    }
    cout << ans;
}