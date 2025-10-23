#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        // TREE EERT
        // TREE ERT
        // TREE RT
        // TREE T
        // TREE
        // naive n^2 is pop one char from front of reverse string and constantly check if pref + suff == palin
        // iter through until we reach two consectuive chars, we can iter through n - 1 because it can be easily proven we will never need to push the nth element
        // nonono very stupid
        string suff = "";
        int it = 0, n = s.length();
        if (n == 1) {
            cout << s;
            continue;
        }
        
    }
}

// TREEEEREE RT