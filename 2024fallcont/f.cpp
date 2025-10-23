#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<int> copyh;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        vector<int> idx(c);
        for (int j = 0; j < c; j++) {
            cin >> idx[j];
            idx[j] += 1;
        }
        for (int j = 0; j < c; j++) {
            h[idx[j]] = 0;
        }

        copyh = h;
        sort(copyh.begin(), copyh.end());
        
        int sum = 0;
        int l = 0, r = n - 1;
        while (sum != b && l < r) {
            sum = copyh[l] + copyh[r];
            if (sum > b) r--;
            else l++;
        }
        for (int j = 0; j < n; j++) {
            if (copyh[j] == b) sum = copyh[j];
        }
        cout << sum << endl;
        if (c == 0) cout << "\n";
        if (sum == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}