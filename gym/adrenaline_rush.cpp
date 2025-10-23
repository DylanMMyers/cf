#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\adrenaline_rush.exe
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // every car should overtake every car thats in front of it, then the ones that need to keep moving back continue while others stop
    // so for 2 3 1:
    // 2 takes 1, 3 takes 1, 1 must stop, next
    // 3 takes 2, next
    // 2 takes 3, next
    // finished

    // so just hash pairs to see if the swap has been done in the given order before, if it has been done don't do it
    // it should work itself out to where if a pair has been done, we just continue along and the elements in front/behind that haven't been used balance it out

    // ***nvm, move element to far left and back, then move it to its spot on the right
    // start from back, maximizes double swaps that ae possible

    int n, curr, idx, tr_idx; // idx is where it needs to go, tr_idx is where it is
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> start(n);
    for (int i = 0; i < n; i++) {
        start[i] = i + 1;
        mp[start[i]] = i;
    }

    vector<pair<int,int>> ans;

    for (int i = n - 1; i > 0; i--) {
        idx = i;
        tr_idx = mp[v[i]];
        curr = start[tr_idx];
        for (int j = 1; j <= tr_idx; j++) { 
            // cout << curr << ' ' << start[tr_idx - j] << "\n";
            ans.push_back({curr, start[tr_idx - j]});
        }
        for (int j = 0; j < tr_idx; j++) { 
            // cout << start[j] << ' ' << curr << "\n";
            ans.push_back({start[j], curr});
        }
        for (int j = tr_idx; j < idx; j++) {
            // cout << start[j + 1] << ' ' << curr << "\n";
            ans.push_back({start[j + 1], curr});
            mp[start[j + 1]]--;
            start[j] = start[j + 1];
        }
        start[i] = curr;
        mp[curr] = i;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << "\n";
    }
}