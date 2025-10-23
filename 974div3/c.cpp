#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        // sum of iwealth must be < twealth/2n
        // find richest person, how much do we add (x) to piss everyone off
        long long n;
        cin >> n;
        vector<long long> v;
        v.clear();
        long long tw = 0;
        long long temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            tw += temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        long long half = v.size() / 2;
        // 1 2 3 4 5
        // 0 1 2 3 4
        //     2
        // 1 2 3 4
        // 0 1 2 3
        //     2

        // half is idx of last person to piss off
        // half / sum of wealth = avg

        if (n <= 2) cout << -1 << endl;
        else if (v[half] * n * 2 < tw) cout << 0 << endl; // midde class is alr pissed
        else { // middle class is not yet pissed
            // 1 2 3 4
            // half = idx 2 (3), tw = 10
            // 3 < tw/n means robinhood appears
            // half*2*n > tw
            // 24 > 10
            long long iter = 0;
            while (v[half] * n * 2 >= tw) {
                iter++;
                tw++;
            }
            cout << iter << endl;
        }
    }
}