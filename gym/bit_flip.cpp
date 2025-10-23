#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    unsigned int n, m = 4294967295;
    for (int i = 0; i < q; i++) {
        cin >> n;
        n ^= m;
        cout << n << endl;
    }

}