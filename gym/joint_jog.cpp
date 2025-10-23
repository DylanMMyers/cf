#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\file.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double skx, sky, sox, soy, ekx, eky, eox, eoy;
    cin >> skx >> sky >> sox >> soy >> ekx >> eky >> eox >> eoy;
    double start = (sky - soy) * (sky - soy) + (skx - sox) * (skx - sox);
    double end = (eky - eoy) * (eky - eoy) + (ekx - eox) * (ekx - eox);
    double ans = max(sqrt(start), sqrt(end));
    cout << setprecision(15);
    cout << ans;
}