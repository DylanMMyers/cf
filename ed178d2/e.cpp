#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\e.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
    
        // Precompute next occurrence table
        vector<vector<int>> next(n + 2, vector<int>(k, n));
        for (int c = 0; c < k; ++c) next[n][c] = n;
        for (int i = n - 1; i >= 0; --i) {
            for (int c = 0; c < k; ++c)
                next[i][c] = next[i + 1][c];
            next[i][s[i] - 'a'] = i;
        }
    
        int q;
        cin >> q;
        while (q--) {
            string t;
            cin >> t;
            int pos = 0;
            bool pleasant = true;
            // Try to match t as a subsequence
            for (char ch : t) {
                if (next[pos][ch - 'a'] == n) {
                    pleasant = false;
                    break;
                }
                pos = next[pos][ch - 'a'] + 1;
            }
            if (!pleasant) {
                cout << 0 << '\n';
                continue;
            }
    
            // REAL SOLUTION IS TO NOW GREEDILY FIND THE LATEST LETTER AND JUMP TO IT AFTER WE HAVE REACHED WHERE OUR SUBSEQUENCE ENDS, CAN USE BS TO FIND IDX, PROB WAY TOO SLOW
            // YES USE DP TO PRECOMP AND CAN QUERY IN O(1)

            // Now, try to append letters until t is no longer a subsequence
            int appended = 0;
            while (true) {
                int min_next = n;
                for (int c = 0; c < k; ++c)
                    min_next = min(min_next, next[pos][c]);
                if (min_next == n) break; // No letter can extend the match
                // Greedily choose any letter that allows extension (all are equivalent)
                pos = min_next + 1;
                ++appended;
            }
            cout << appended + 1 << '\n';
        }
    }
}