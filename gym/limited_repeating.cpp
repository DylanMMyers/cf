#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\limited_repeating.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int low = 0, high = 1e9; // bs all possible values of min ele
        while (low < high) {
            int mid = (low + high) / 2, c = k;
            for (int i = 0; i < n; i++) { // iter through list
                if (s[i] == 'B' && v[i] > mid) { // if value should be blue and greater than our desired value (mid), lets paint it (we have to, greedy)
                    while (i < n && (s[i] == 'B' || v[i] <= mid)) { // for every value after it that should be blue or should be red and is less than the value, we can keep painting them
                        i++;                                        // eg mid = 5, if we find a value that wants to be blue and is 6, we have to paint it, then painting any value after it less than 6
                    }                                               // does nothing, so we should keep looking until we find a value that, if painted, would be greater than our mid
                    c--; // -1 for each segment we need to draw to make mid the min penalty
                }
            }
            if (c < 0) low = mid + 1; // if we have a mid which takes more than k paintings, we know we can't get this min or any lower anymore
            else high = mid;
        }
        cout << low << "\n";
    }
}