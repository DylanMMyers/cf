#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\mountain_range.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int n; cin >> n;
        list<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            v.push_back({x, i});
        }
        if (n == 1) {
            cout << 1;
            continue;
        }
        vector<int> dp(n, 1);
        priority_queue<int, vector<int>, greater<int>> minq;
        unordered_map<int,vector<list<pair<int,int>>::iterator>> mp;
        list<pair<int,int>>::iterator it = v.begin();
        while (it != v.end()) {
            minq.push((*it).first);
            mp[(*it).first].push_back(it);
            it++;
        }
        // so how do we sort the elements?
        while (!minq.empty()) {
            int curr = minq.top();
            minq.pop();
            list<pair<int,int>>::iterator it = mp[curr].back();
            mp[curr].pop_back();
            // so curr is the curr mountain
            // it contains the value and the real index (dp array index)
            if (it != v.begin()) {
                if ((*prev(it)).first > (*it).first) dp[(*(prev(it))).second] = max(dp[(*(prev(it))).second], dp[(*it).second] + 1);
            }
            if (next(it) != v.end()) {
                if ((*next(it)).first > (*it).first) dp[(*(next(it))).second] = max(dp[(*(next(it))).second], dp[(*it).second] + 1);
            }
            v.erase(it);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << dp[i] << " \n"[i == n - 1];
        // }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
}

// so the premise is fine, but I need to not just consider elements one to the right or left, but instead the nearest element greater than the current mountain
// how can i organize the indices such that I can find the closest mountain on the left and right which has a height greater than the current mountain?
// once we establish this, we just need to keep the minq idea and process each mountain from smallest to largest, then we just take max_element of dp and thats our ans
// the dp state is just the current count of jumps, updating the state consists of comparing the lower mountains score + 1 with the higher mountains score
// what is the time complexity of finding the element on our left and right which is greater than our current element?
// its O(n), as we could have 40 1 ... 1 39 and have to search entire array
// is there a way we can have a smart sweep to arrange the mountains in such a way where we can have something that evens out to O(n) or O(nlogn) for all cases?
// wait, even better
// since we process the mountains from smallest to largest, what if every time we process a node, we just "remove" the current mountain from the range
// so lets says we have 20 15 17, after processing 15 there will be no element less than 17 (once we move onto processing 17), so what if we treat it like a linked list?
// then we can say 20 - 15 - 17 goes to 20 - 17, and we have processed 15 so all the info from it is now redundant anyway. this works!


// so we will always start from the tallest mountain, which means we can do bottom up from the smallest mountains and find the most mountains that can be travelled to
// so the dp state is just {num_mountains} at a mountain m_i, where we try to travel to each adjacent mountain if its exclusively taller. We count a m_i as visited if 
// the mountain has no unvisited neighbors which are less than it. Then we update the current dp state to be the most optimal path "down" where we choose the highest count
// we will go from the min first, as this is the basis for bottom up solution