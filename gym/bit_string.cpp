#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    ll t = 2, M = 1000000007;
    for (int i = 1; i < x; i++) {
        t *= 2;
        t = t % M;
    }
    cout << t << endl;
}