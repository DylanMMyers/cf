#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe
// g++ file.cpp -o file

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a = 1;
    for (int i = 1; i < 30; i++) {
        a *= i;
    }
    cout << a;
}