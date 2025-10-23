#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve() {
    string key;
    cin >> key;
    string word;
    cin >> word;
    unordered_map<char, int> mp;
    for (int i = 1; i < 27; i++) {
        mp[key[i]] = i;
    }
    ll ans = 0;
    for (int i = 1; i < word.size(); i++) {
        ll left, right;
        left = mp[word[i - 1]];
        right = mp[word[i]];
        if (left - right < 0) ans += right - left;
        else ans += left - right;
    }
    cout << ans << endl;
}
 
int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}