#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe
// g++ file.cpp -o file

class Manacher {
public: 
    // p[i] = radius of longest palindrome centered at i 
    vector<int> p;        
    string ms;        

    Manacher(string &s) {
        ms = "@"; 
        for (char c : s) {
            ms += "#" + string(1, c);
        }
        ms += "#$"; 
        runManacher();
    }

    void runManacher() {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n - 1; ++i) {
            int mirror = l + r - i;
            if (i < r)
                p[i] = min(r - i, p[mirror]);

            while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]]){
                ++p[i];
            }

            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    // returns length of longest palindrome centered 
    // at 'cen' in original string
    // 'odd' = 1 → check for odd-length, 'odd' = 0 → even-length
    int getLongest(int cen, int odd) {        
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    // checks if s[l..r] is a palindrome in O(1)
    bool check(int l, int r) {
        int len = r - l + 1;
        int cen = (l + r) / 2;
        return len <= getLongest(cen, len % 2);
    }
};