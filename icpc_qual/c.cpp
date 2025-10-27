#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./c.exe
// g++ c.cpp -o c
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        s.insert(d);
    }
    cout << min((int)s.size(), k);
}