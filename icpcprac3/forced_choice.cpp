#include <bits/stdc++.h>
#define ll long long
using namespace std;
// g++ forced_choice.cpp -o forced_choice
// Get-Content t.txt | .\forced_choice.exe

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, s; cin >> n >> p >> s;
    for (int i = 0; i < s; i++){
        int m; cin >> m;
        bool hasCard = false;
        for (int j = 0; j < m; j++){
            int a; cin >>a;
            if (a == p) hasCard = true;
        }
        if (hasCard) cout << "KEEP\n";
        else cout << "REMOVE\n";
    }
    // vector<int> removed(n, 0);

    // for (int i = 1; i <= n; i++) cards.insert(i); // IMPROVE

    // vector<set<int>> plays(s);
    // set<int> removed;
    // for (int i = 0; i < s; i++){
    //     int a; cin >> a;
    //     set<int> play;
    //     for (int j = 0; j < a; j++){
    //         int b; cin >> b;
    //         play.insert(b);
    //     } plays[i] = play;
    // }
    // // work backwards
    // // check if has p -> KEEP
    // // check if has already removed card -> KEEP
    // // else -> REMOVE
    // for (int i = s-1; i >= 0; i--){

    // }
}