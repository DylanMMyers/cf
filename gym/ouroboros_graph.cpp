#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\ouroboros_graph.exe

int MOD = 998244353;
vector<vector<int>> al;
vector<int> dp0, dp1;

void dfs(int u) {
    for (int child : al[u]) {
        dfs(child);
    }
    int k = al[u].size();
    if (!k) {
        dp0[u] = 1;
        dp1[u] = 1;
        return;
    }
    vector<int> pref(k + 1, 1), suff(k + 1, 1);
    for (int i = 0; i < k; i++) {
        int v = al[u][i];
        int sum = (dp0[v] + dp1[v]) % MOD;
        pref[i + 1] = pref[i] * sum % MOD;
    }
    for (int i = k - 1; i >= 0; i--) {
        int v = al[u][i];
        int sum = (dp0[v] + dp1[v]) % MOD;
        suff[i] = suff[i + 1] * sum % MOD;
    }
    dp0[u] = pref[k];
    int ways = 0;
    for (int i = 0; i < k; i++) {
        int v = al[u][i];
        int cont = dp1[v] * pref[i] % MOD * suff[i + 1] % MOD;
        ways = (ways + cont) % MOD;
    }
    dp1[u] = ways;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        // so we have some graph that is input as a tree
        // we then draw edges connecting all leaf us to the root (1)
        // then, we can remove some edges including the ones we have just created from the graph
        // our goal is to determine how many different graphs mod 998224353 there are by doing these removals in some order

        // with the problem defined, what are some observations:
        // does the order in which we remove the edges matter?
        // no, we should just choose some place to sweep from
        // this is almost certainly a dp problem, how to define the state?
        // i think for every egde we delete we can see how many new graphs have been created based on how many other graphs that edge was a part of
        // then we just iterate over every edge and we will determine how many more combinations along with changing its dp state for the other edges
        // the base case is the initial graph, which is 1 (so at dp[init], the edge is only a part of one graph until we operate)

        // how can we iterate?
        // what is the dp state?
        // the observation is that when we remove an edge, it can only be removed so many times
        // i think it can be just math formula, not even dp
        // we have the case where we remove 1 edge for all graphs, 2 edges, ... up to n edges
        // it is easy? to determine this

        // how do we calculate this, or is dp just easier, should we calculate how many graphs an edge is a part of and add them up or take a diff approach
        // dp is prob easier, but how do we go about this

        // not dp, can just do math at each edge
        // missed the fact that we want trees, so every 
        
        int n;
        cin >> n;
        dp0.assign(n + 1, 0);
        dp1.assign(n + 1, 0);
        al.assign(n + 1, {});
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            al[a].push_back(b);
        }
        dfs(1);
        cout << dp0[1];
    }
}