#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int x;
    cin >> x;
    int b = 1, it = 0, count = 0;
    while ((b << it) <= x) {
        if ((b << it) & x) count++;
        it++;
    }
    cout << count << endl;
}