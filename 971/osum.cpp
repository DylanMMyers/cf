#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int r;
        cin >> r;
        vector<int> a(r);
        for (int i = 0; i < r; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '#') a[i] = j + 1;
            }
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            cout << a[i] << ' ';
        }
        cout << endl;

    }
    return 0;
}