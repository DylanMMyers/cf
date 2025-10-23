#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\cat_fox_and_the_lonely_array.exe

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mid, low = 1, high = n;
    bool flag = true;
    vector<int> set(31, 0);
    while (low < high) {
        // write binary search where:
        // if we find a k that works: cut off everything above
        // if we find a k that doesn't: cut off everything below
        // update ans if we find a k that works
        mid = (high + low) / 2;
        flag = true;
    
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < n; j++) {
                set[j] = ((1 << j) & v[j]);
            }
        }
        

        if (flag) high = mid;
        else low = mid + 1;
    }
    
    cout << low << "\n";
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