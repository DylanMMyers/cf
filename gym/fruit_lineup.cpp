#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\fruit_lineup.exe

ll MOD = 998244353, nn = 4001001;
vector<ll> fact(nn + 1, 0), invFact(nn + 1, 0);
ll modPow(ll a, ll e) {
    ll res = 1;
    a %= MOD;
    while (e > 0) {
        if (e & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return res;
}
ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}
void precomp() {
    fact[0] = 1;
    for (ll i = 0; i < nn; ++i) {
        fact[i + 1] = (fact[i] * (i + 1)) % MOD;
    }
    invFact[nn] = modPow(fact[nn], MOD - 2);
    for (ll i = nn; i >= 1; i--) {
        invFact[i - 1] = (invFact[i] * i) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while (tt--) {
        ll a, b, c, d, n;
        cin >> a >> b >> c >> d;
        n = a + b + c + d;
        precomp();
        // apple -> banana
        // apple -> grape
        // orange -> grape
        // a: apples, b: oranges, c: bananas, d: grapes
        // so valid consists of:
        // apple orange banana grape
        // apple orange grape banana
        // apple banana orange grape
        // orange apple banana grape
        // orange apple grape banana
        // so should we just do multiple sweeps where we do all the different "orientations"
        // so lets think about where we can place the apples and oranges since they are limited
        // apples can be placed anywhere to the left of bananas and grapes, so this will provide us info later

        // how can we solve this problem brute force?
        // we simply would place one of four items in our order, then recursively continue doing this for each position
        // then we would check over each permutation and we can verify if every a is left of c d and if every b is left of d

        // how can we make this brute force solution more efficient?
        // well, if we have placed specifically a grape we know that the elements to the right will no longer be apples or oranges
        // if we specifically place a banana, we know elements to the right will not be apples
        // this would slightly speed up our brute force solution
        // we also know we cannot place bananas/grapes for at least count(apples)
        
        // maybe the multiple sweeps is a good approach because it allows us to breakdown where all the apples/oranges in a given ordering 
        // must be without needing to calculate them in tangent with each other
        // for example if we plan on placing all apples and oranges in some permuation of (apples, oranges, grapes, bananas) we know that we can just 
        // calculate all combinations of grapes and bananas together, then calculate for (apples, bananas, oranges, grapes) etc

        // so then we can just use some clever orderings and simple dp of combination counts across each preset ordering and find the sum of combinations

        // so lets define the preset orders
        // {apple/orange, grape/banana}
        // {apple, banana/orange, grape}
        
        // but how do we consider edge cases where we have something like banana and orange overlap, as bananas
        // is this also a seperately handled case? what do we do
        // then the answer is just the product of possible placements, for example in the first a slots its always 2 because we can place apple/orange there
        
        // yea so i was right it isnt even dp, we can anchor the leftmost

        ll ans = 0;
        for (ll i = a; i < min(a + b + 1, n - c); i++) {
            ans = (ans + C(i - 1, a - 1) * C(n - i, c)) % MOD;
        }
        cout << ans << "\n";
    }
}