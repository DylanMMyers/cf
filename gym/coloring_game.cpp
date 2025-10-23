#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\coloring_game.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        // so we can essentially just count all the combinations where two numbers are greater than one number...
        // seems like we can do O(n^2 * logn) or something more clever which is slightly faster, but we can easily count
        // wait
        // lets not be 1q and think about how bob can select the tiles optimally
        // bob can either select one of alices colored tiles and decrease her score enough to win, if it isnt greater than the other two he loses
        // bob can choose some element that isnt already chosen that is greater than half of alices score
        // i think per pair we can easily establish in O(1) whether we can choose one element from alices picks
        // then we can binary search the rest of the array to find how many elements would work for the given combo
        // O(n^2 * logn) in worse case is 5000*5000*log(5000) which is 308000000 
        // so then we are ez solve
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        // well, lets just assume we can say bob picks two elements, if alice can pick one greater than it she wins
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // instead of searching for the element which is larger than half of the sum of the current two, we should search for the max of half + 1 and also consider if bob were to select
                // the current max element of the selection
                // ANS
                // we need to check how many combinations exist where we take the minimum element and add it to the current element of the binary search, and see where they are greater than the maxi
                // element without exceeding the maxi element (we need to find both ends of the range) then we take this total range and subtract up to both numbers from it, then add it to ans
                // the lower bound is the first instance where the element added to the min is less than the max
                int x = max(v[n - 1], 2 * v[i]) - v[i] - v[j];
                int k = upper_bound(v.begin(), v.begin() + j, x) - v.begin();
                ans += j - k;
            }
        }
        cout << ans << "\n";
    }
}