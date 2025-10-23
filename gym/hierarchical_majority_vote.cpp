#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\hierarchical_majority_vote.exe

vector<int> v;

int dfs() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        int nn, n = 3;
        cin >> nn;
        while (nn > 1) {
            n *= 3;
            nn--;
        }
        v.resize(n);
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            v[i] = s[i] - '0';
        }
        // dfs every path, if ans is 1, we should dfs all one branches and find the k lightest branches to edit (can be greedy at each branch) and vice versa
        // i think if clever, can calculate this sum on the way up, then just pick them once we have res (to change a node from one to another, we would want to change 1s to 0s so we can just calculate that)
        // hmmm how to organize this
        
    }
}