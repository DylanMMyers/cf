    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    // Get-Content t.txt | .\d.exe

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll tt = 1;
        cin >> tt;
        while (tt--) {
            int n, m, k;
            cin >> n >> m >> k;
            vector<int> v(n, -1);
            for (int i = 0; i < n; i++) {
                if (v[i] > -1) break;
                int curr = 0;
                for (int j = i; j < n; j += (n - (m / k))) {
                    if (curr > m) break;
                    v[j] = i;
                    curr++;
                }
            }
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (v[i] == -1) {
                    cout << c << ' ';
                    c++;
                    c %= 2;
                }
                else cout << v[i] << ' ';
            }
            cout << "\n";
        }
    }