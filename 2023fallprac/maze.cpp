#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int idx;

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            idx = i;
            break;
        }
    }

    unordered_map<char, int> keys;
    for (int i = 0; i , n; i++) {
        if (islower(s[i])) keys[s[i]] = 1;
    }

    bool out = false;
    char comp;
    for (int i = idx; i >= 0; i--) {
        if (isupper(s[i])) {
            comp = s[i];
            tolower(comp);
            if (keys.find(comp) == keys.end()) break;
        }
        if (i == 0) out = true;
    }

    for (int i = idx; i < n; i++) {
        if (isupper(s[i])) {
            for (int i = idx; i >= 0; i--) {
        if (isupper(s[i])) {
            tolower(s[i]);
            if (keys.find(s[i]) == keys.end()) break;
        }
        if (i == 0) out = true;
    }
        }
        if (i == n - 1) out = true;
    }

    if (out) cout << "YES";
    else cout << "NO";

    return 0;
    
}