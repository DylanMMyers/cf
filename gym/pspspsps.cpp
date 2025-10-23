#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Get-Content t.txt | .\pspspsps.exe

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // so the only time there is a bad answer is if the gap/positioning of a p and s exist to where the distance doesnt allow early numbers to repeat
    // so like, p...s...p doesnt work because there is a p, then s, then the p occurs later so its not pspsible for the s permutation and second p permutation to both include a 1
    // edge cases, if we have all ., p or s then the answer is yes, or if we have all p or s and some . somewhere
    
    // if we have an s after a p, the answer is no, otherwise answer is yes (consider edge cases)
    // does p need to be final element?
    // *** if we have an s then a p, p must be the final element
    // so we need s then p for a vaid permutation (discarding edge cases), then p must be final element (given it exists)
    // the reason p after s doesnt work is because perms of s should be increasing (1, 2, ... i) while perms of p decrease

    // after 82nd and 235th test case fail im gonna cry

    if (n == 1) {
        cout << "YES\n";
        return;
    }
    if (s[0] == 's') s[0] = '.';
    if (s[n - 1] == 'p') s[n - 1] = '.';
    bool foundp = false, founds = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') foundp = true;
        if (s[i] == 's') founds = true;
    }
    if (foundp && founds) cout << "NO\n";
    else cout << "YES\n";
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