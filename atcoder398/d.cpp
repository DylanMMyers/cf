#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\d.exe

struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        // Combine hashes of individual elements
        hash<T1> h1;
        hash<T2> h2;
        return h1(p.first) ^ (h2(p.second) << 1); // Bit shifting for better distribution
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, r, c;
        cin >> n >> r >> c;
        string s;
        cin >> s;
        unordered_map< pair<int, int>, int, PairHash> mp;
        mp[{0,0}] = 1;
        vector<int> v(n, 0);
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            // in problem statement:
            // n == smoke moves to left
            // s == smoke moves to right
            // e == smoke moves up
            // w == smoke moves down
            if (s[i] == 'N') {
                x++;
                mp[{x,y}] = 1;
                r++;
            }
            else if (s[i] == 'E') {
                y--;
                mp[{x,y}] = 1;
                c--;
            }
            else if (s[i] == 'S') {
                x--;
                mp[{x,y}] = 1;
                r--;
            }
            else {
                y++;
                mp[{x,y}] = 1;
                c++;
            }
            if (mp.find({r,c}) != mp.end()) v[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            cout << v[i];
        }  
    }
}