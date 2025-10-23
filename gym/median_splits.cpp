#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\median_splits.exe

// def of ordered_set
// order_of_key(x) gives us position of x in tree
// find_by_order(k) gives us the kth element in the set (we can pass size / 2 + [0,1][size % 2 == 1] to find the med of the current segment)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        // if (v.front() <= k && v.back() <= k) {
        //     cout << "YES\n";
        //     continue;
        // }
        ordered_set L; // find ordered set template with rb impl, need to pass key/2 as size so we can easily find med, placeholder for now
        int med_L = 1e9 + 1, med_M = 1e9 + 1, med_R = 1e9 + 1, it = 0;
        bool ans = false;
        // so we will add values until the med is <= k or until we decide there is no valid L where med <= k
        while (med_L > k && it < n - 2) {
            L.insert({v[it], it});
            it++;
            med_L = (*(L.find_by_order((L.size() - 1) / 2))).first;
        }
        // then we will try to keep adding values as long as they are greater than the med and don't move med(L) > k again
        while (it < n - 2) {
            if (v[it] > k) {
                L.insert({v[it], it});
                it++;
                if ((*(L.find_by_order((L.size() - 1) / 2))).first > k) {
                    L.erase({v[it], it - 1});
                    it--;
                    break;
                }
            }
            else break;
        }
        // then we will see if there is a valid mid to go with L
        ordered_set M;
        while (med_M > k && it < n - 1) {
            M.insert({v[it], it});
            it++;
            med_M = (*(M.find_by_order((M.size() - 1) / 2))).first;
        }
        if (med_L <= k && med_M <= k) {
            cout << "YES\n";
            continue;
        }
        // if not, we will see if there is a valid R to go with L
        ordered_set R;
        int it_r = n - 1;
        while (med_R > k && it_r > L.size()) {
            R.insert({v[it_r], it_r});
            it_r--;
            med_R = (*(R.find_by_order((R.size() - 1) / 2))).first;
        }
        if (med_L <= k && med_R <= k) {
            cout << "YES\n";
            continue;
        }
        // then we will now check for a valid R in the same way we found L
        R.clear();
        it_r = n - 1;
        med_R = 1e9 + 1;
        while (med_R > k && it_r > 1) {
            R.insert({v[it_r], it_r});
            it_r--;
            med_R = (*(R.find_by_order((R.size() - 1) / 2))).first;
        }
        // continue adding if we can (value is > k and doesn't change med(R) to be > k)
        while (it_r > 1) {
            if (v[it_r] > k) {
                R.insert({v[it_r], it_r});
                it_r--;
                if ((*(R.find_by_order((R.size() - 1) / 2))).first > k) {
                    R.erase({v[it_r], it_r + 1});
                    it_r++;
                    break;
                }
            }
            else break;
        }
        // then we will try to find a valid mid to go with R in the same way we did before, but from the right now 
        M.clear();
        med_M = 1e9 + 1;
        while (med_M > k && it_r > 0) {
            M.insert({v[it_r], it_r});
            it_r--;
            med_M = (*(M.find_by_order((M.size() - 1) / 2))).first;
        }
        if (med_R <= k && med_M <= k) {
            cout << "YES\n";
            continue;
        }
        // if we never found a valid pair out of all the comboss we just report NO
        cout << "NO\n";
    }
}