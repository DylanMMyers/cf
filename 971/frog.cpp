#include <iostream>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y, k;
        cin >> x >> y >> k;
        int ans = 0;
        int l, r;

        l = (x + k - 1) / k;
        r = (y + k - 1) / k;

        int maxi = 2 * max(l, r);
        if (l > r) maxi--;
    
        cout << maxi << endl;
    }

    return 0;
}

