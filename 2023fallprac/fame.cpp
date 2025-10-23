#include <iostream>

using namespace std;

int main() {
    double l, d, x;
    cin >> l >> d >> x;
    x /= 100;

    if (l / (l + d) >= x) cout << '0';
    else {
        int iter = 0;
        while (l / (l + d) < x) {
            l++;
            iter++;
        }
        cout << iter;
    }

    return 0;
    
}