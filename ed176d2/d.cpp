#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

ll dfs(set<ll> s, ll target, ll currscore, ll curr) {
    if (curr == target) return currscore;
    if (curr < target) return (ll)1e9;

    for (auto ele : s) {
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        ll x, y;
        cin >> x >> y;
        if (x == y) {
            cout << "0\n";
            continue;
        }
        vector<ll> a, b;
        while (x > 0) {
            a.push_back(x);
            x /= 2;
        }
        while (y > 0) {
            b.push_back(y);
            y /= 2;
        }
        // the idea is, if we have a larger number which reaches a common number with the smaller, we will be able to divide by 2 some k times and reach a similar number
        // one way minimizes it, by doing /2, /4, /8... instead of just dividing once. Refactoring the greater number reduces this score, and we divide the other number by just what brings 
        // it to the similar number. Edge case would be for if two numbers aren't equal, but are like x, y = x + 1. Then, after /2 both x and y equal, so we need to do /2, /4, then /8 for other.
        // If either number reaches 0 before /2 /4 reaches a common number, then the answer is /2 /4, ... until both are 0

        // now just use two pointers and see if we can find an equal point, otherwise we will just divide by some massive numbers until both reach 0
        int l = 0, r = 0, ans = 0;
        int n = a.size(), m = b.size();
        while (l < n && r < m) {
            if (a[l] == b[r]) break;

            if (a[l] < b[r]) r++;
            else l++;
        }
        // now we know where l and r end, lets check if the idx are equal and handle if not separately
        set<ll> s;
        ll score = 2;
        while (score < 10e17) {
            s.insert(score);
            score *= 2;
        }
        // now with our set of dfs, remove current number we use, return minimum score to reach this similar number
        // probably easy to prove that the earliest number will always yield the lowest score, so this is fine
        ll ans, target;
        if (l == n || r == m) target = 0;
        else target = a[l];
        ans = dfs(s, target, 0, 0);
        cout << ans << "\n";
    }
}