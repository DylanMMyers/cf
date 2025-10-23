#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\a.exe

void solve() {
    int a, b, c, d, e;
    cin >> a >> b >> d >> e;
    c =  d - b;
    int ans = 0, curr = 0;
    if (c == (b + a)) ans++;
    if (d == (c + b)) ans++;
    if (e == (d + c)) ans++;

    c = a + b;
    if (c == (b + a)) curr++;
    if (d == (c + b)) curr++;
    if (e == (d + c)) curr++;
    ans = max(curr, ans);

    c = e - d, curr = 0;
    if (c == (b + a)) curr++;
    if (d == (c + b)) curr++;
    if (e == (d + c)) curr++;
    ans = max(curr, ans);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}