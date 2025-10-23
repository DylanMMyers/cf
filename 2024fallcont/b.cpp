#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        if (temp == "ON") v[i] = 1;
        else v[i] = 0;
    }



    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            ans++;
            for (int j = i; j < n; j++) {
                if (v[j] == 1) v[j] = 0;
                else v[j] = 1;
            }
        }
    }

    cout << ans;

    return 0;
}