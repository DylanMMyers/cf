#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, q;
        cin >> n >> q;
        vector<long long> x(n);
        vector<long long> k(q);
        for (long long i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (long long i = 0; i < q; i++) {
            cin >> k[i];
        }
        
        // a given element that does not have a point, x, has the segments of the element before/after minus its previous segments
        // if a given point is in x, it will have a base value of connecting with all other points plus all segments passing over it
        // if a given point is not in x, it will have sum of all segments passing over it

        // for a base case (segments passing over): points before * points after
        // for the points in x, add an additional n segments (it connects with every other point)

        // so when we come across some gap in the range, say ...3, 5... where 4 is missing
        // the sum is the same for all values in between this
        // so ...3, 6... where 4 and 5 have the same amount of segments, therefore for each value in between this gap an additional k ->
        // segments can be added to the respective count

        unordered_map<long long, long long> a;
        long long nums;
        long long segments;

        for (long long i = 0; i < n - 1; i++) {
            if (x[i] + 1 < x[i + 1]) {
                // 1 2 3 4 5 <6, 7> 8 9
                //         i = 4
                nums = x[i + 1] - x[i] - 1;
                segments = (n - (i + 1)) * (i + 1);
                if (a.find(segments) == a.end()) a[segments] = 0;
                a[segments] += nums;
            }

            segments = (n - (i + 1)) * (i);
            segments += n - 1;
            if (a.find(segments) == a.end()) a[segments] = 0;
            a[segments]++;
        }
        a[n - 1]++; // for final element in x

        for (long long i = 0; i < q; i++) {
            cout << a[k[i]] << ' ';
        }
        cout << endl;
    }

    return 0;
}