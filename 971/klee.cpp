#include <iostream>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        // for 2 2, array is [2, 3]
        // sum of all numbers between l and r is S = (r - l + 1)(l + r)/2
        // to find best min, its S / 2 becomes negative
        // idx of S / 2 is idx = (S / 2) - 1

        int r = k + n - 1;
        int l = k;
        int s = (n * (l + r)) / 2;
        int st = s/2;
        //if (s % 2 == 1) st++;
        
        // now, subtract n + k -- from s until sum is half
        
        int ans = 0, iter = 0;

        while (ans < st) {
            ans += l;
            l++;
            iter++;
        }

        cout << iter << endl;

    }

    return 0;
}