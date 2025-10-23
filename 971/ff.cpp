#include <iostream>
#include <vector>

using namespace std;

int main() {
    long tt;
    cin >> tt;
    while (tt--) {
        long n, q;
        cin >> n >> q;
        vector<long> v(n);
        for (long i = 0; i < n; i++) {
            cin >> v[i];
        }

        long on = 0;
        for (long i = 0; i < n; i++) {
            on += v[i];
        }

        // 1 2 3
        // segment tree?
        long iter = 1;
        while (iter < n) {
            for (long i = iter; i < n; i++) {
                v.push_back(v[i]);
            }
            for (long i = 0; i < iter; i++) {
                v.push_back(v[i]);
            }
            iter++;
        }

        long c;
        for (long i = 0; i < q; i++) {
            long l, r;
            cin >> l >> r;
            l--;    

            // IF TLE, IMPLEMENT SEGMENT TREE -> start
            /*for (long j = l; j < r; j++) {
                c += v[j];
            }*/

            // dont even need segment tree, calculate sum of entire array then cut out extras ->
            // if l and r are more than 1 n apart, then the sum is sum of 1 n + remainder
            // eg 1,2,3,2,3,1,3,1,2 from 2 to 7
            // 2,3,2,3,1,3
            // so from 2 to 2 % 3 (to) 7 - (7 % 3) to 7 or 0 to 2 and 6 to 7 of subarray is all that needs calculated,

            long l2 = l % n, r2 = r - (r % n);

            int sum = on * (r - l) / n;

            for (int i = l; l < l2; l++) {
                sum += v[i];
                cout << "did" << endl;
            }
            for (int i = r2; i < r; i++) {
                sum += v[i];
                cout << "did2" << endl;
            }

            // finish

            cout << sum << endl;

        }

        // 1,2,3
        // 1,2,3,2,3,1,3,1,2
        // {1,2,3,2,3,1,3,1,2}


    }

    return 0;
}