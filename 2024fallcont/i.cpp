#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    string t;
    cin >> t;

    // T.T..T..TT.T..T..TT.T..T..TT.T..T..TT.T..T..TT.T..T..TT.T..T..TT.T..T..T

    long long mini;

    long long tcount = 0;
    for (long long i = 0; i < n; i++) {
        if (t[i] == 'T') tcount++;
    }
    if (tcount < k) cout << -1;
    else if (k == 1) cout << 0;
    else {
        long long l = 0, r = 0, curr = 0;
        mini = LLONG_MAX;
        if (t[l] == 'T') curr++;
        while (r < n) {
            if (r == l) r++;
            else if (curr < k) {
                if (t[r] == 'T') curr++;
                r++;
                mini = min(mini, r - l);
            }
            else {
                if (t[l] == 'T') curr--;
                l++;
                mini = min(mini, r - l);
            }
        }
    }
    
    if (k % 2 == 0) cout << mini - 1;
    else cout << mini;


    return 0;
}