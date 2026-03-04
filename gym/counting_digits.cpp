#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\counting_digits.exe
// g++ counting_digits.cpp -o counting_digits

int dp[20][10][2][2];
// finding number of numbers having no adjancent digit from 0 to n
int solve(string& num, int n, int prev_dig, int i, bool leading_zeroes, int tight) {
    if (i == n) {
        return(1);
    }
    if (prev_dig != -1 && dp[i][prev_dig][leading_zeroes][tight] != -1) {
        return dp[i][prev_dig][leading_zeroes][tight];
    }
    // bounds for the ith digit - possible values for the ith digit
    int lb = 0;
    int ub = (tight == 1) ? (num[i] - '0') : 9;
    int ans = 0;
    for (int dig = lb; dig < ub + 1; dig++){
        // case of similar adjancent digits
        if (dig == prev_dig && dig != 0) continue;
        // case when '00' occurs in the number (but not at the start(seen from left side))
        if (dig == prev_dig and dig == 0 && leading_zeroes == 0) continue;
        ans += solve(num, n, dig, i+1, leading_zeroes & dig == 0, tight & (dig == ub));
    }
    return (dp[i][prev_dig][leading_zeroes][tight] = ans);
}

bool check(string a){
    int ns = a.size();
    bool flag = true;
    for (int i = 1; i < ns; i++) {
        if (a[i - 1] == a[i]) flag = false;
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    string a, b; cin >> a >> b;
    int na = a.size();
    int nb = b.size();
    memset(dp, -1, sizeof(dp));
    int ans = solve(b, nb, -1, 0, 1, 1);
    memset(dp, -1, sizeof(dp));
    ans -= solve(a, na, -1, 0, 1, 1); 
    ans+= check(a) ? 1 : 0;
    cout << ans << "\n";      
}