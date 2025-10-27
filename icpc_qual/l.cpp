#include <bits/stdc++.h>
#define ll long long
// Get-Content t.txt | ./l.exe
// g++ l.cpp -o l
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a = 0;
    int b = 0;
    int c = 0;
    //set<int> seen;
    for (int i = 0; i < n; i++){
        int j; cin >> j;
        if (i==0)a=j/3;
        if (i==1)b=j-a-a;
        if (i==n-1)c=j/3;
        //seen.insert(j);
    }
    // for (int x : seen){
    //     int j = x - a - c;
    //     if (j*3!=x&&j!=a && j!=c && seen.find(j*3) != seen.end()){
    //         b = j;
    //         break;
    //     }
    // }
    cout << a << " " << b << " " << c << '\n';
}