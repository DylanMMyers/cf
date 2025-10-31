#include <bits/stdc++.h>
#define ll long long
using namespace std;
// g++ 01seq.cpp -o 01seq
// Get-Content t.txt | .\01seq.exe
// https://open.kattis.com/problems/sequences

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int MOD = 1e9 + 7;
    string s; cin >> s;
    int n = s.length();
    int ans = 0, sum = 0, k = 1;
    // when we split off:
    // if 0, we add to the count once by increasing all other paths by one node (2^k)
    // if 1, we dont add to the count of previous (earlier i) but still must move across all later verse
    // so need to maintain sum of all later verse, then when we encounter ? we only add the 0's contribution
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            // this must be crossed across all k-verse
            sum = (sum + k) % MOD;
        }
        else if (s[i] == '1') {
            // this must move the sum of all necessary moves across all universe
            ans = (ans + sum) % MOD;
        }
        else {
            // the 1 must move across all sums in all existing universe, but not the newly created one
            ans = ((ans + ans) % MOD + sum) % MOD;
            // all future 1/0 will need to cross sum in the existing universe + k (0) as well as the fork verse of one (1),  
            sum = ((sum + sum) % MOD + k) % MOD;
            k = (k + k) % MOD;
        }
    }
    cout << ans;
}