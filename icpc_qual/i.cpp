#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./i.exe
// g++ i.cpp -o i
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a;
    priority_queue<int> s;
    for (int i = 0; i < n; i++){
        int j; cin >> j;
        a.push_back(j);
    }
    for (int i = 0; i < n; i++){
        int j; cin >> j;
        s.push(j);
    }
    double best = 0;
    ll memberTotal = 0;
    for (int i = 0; i < n; i++){
        memberTotal += s.top(); s.pop();
        best = max(best,(double)(a[i] + memberTotal)/(i+1));
    }

    cout << fixed << setprecision(6) << best << '\n';
}