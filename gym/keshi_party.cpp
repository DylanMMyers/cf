#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\keshi_party.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
        // does prioq work?
        // i <3 prioq
        // can store the friend who is the least stingy about his friends, should this always select the best friends?
        // this has some downsides, mainly for overlap conflicts
        // like if we store some friend who has {1, 1e9} and one who has {1e9, 1} the range is very large but they might be less compatible than some other friends
        
    }
}