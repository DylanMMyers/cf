#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> x(n);
        vector<int> y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        // unique xs, does y = 1 exist
        int uy = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < y.size(); i++) {
            if (y[i] == 0) continue;
            else {
                if (mpp.find(y[i]) == mpp.end()) uy++;
                mpp[y[i]] = 0;
            } 
        }

        int u = 0;

        unordered_map<int, int> mp;
        for (int i = 0; i < x.size(); i++) {
            if (mp.find(x[i]) == mp.end()) u++;
            mp[x[i]] = 0;
        }

        if (uy == 0 || u == 0) cout << '0' << endl;
        else cout << u + uy - 1 << endl;
    }

    return 0;
}