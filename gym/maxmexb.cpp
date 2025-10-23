#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        unordered_map<int, int> mp;
        vector<int> v(n);
        vector<int> dupes;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (mp.find(v[i]) == mp.end()) mp[v[i]] = 1;
            else {
                if (mp[v[i]] == 1) {
                    dupes.push_back(v[i]);
                    mp[v[i]]++;
                }
                else mp[v[i]]++;
            }
        }

        int it = 0;
        while (it < n + 1) {
            if (mp.find(it) != mp.end()) {
                it++;
                continue;
            }

            bool found = false;
            for (int dupe : dupes) {
                if ((it - dupe) % x == 0 && mp[dupe] > 1) {
                    mp[it] = 1;
                    it++;
                    mp[dupe]--;
                    found = true;
                }
            }

            if (!found) break;
        }

        cout << it << endl;

    }
    return 0;
}