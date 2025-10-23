#include <bits/stdc++.h>
#define ll long long
using namespace std;


// CUSTOM HASH STRUCT TO USE PAIRS WITH UNORDERED_MAP
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};

pair<int, int> helper(int a, int b) {
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int d = 0, k = 0;
    unordered_map< pair<int, int>, int, HASH> mp;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') d++;
        else k++;
        cout << ++mp[helper(d, k)] << ' ';
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}