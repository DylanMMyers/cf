#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\encode_and_decode.exe
// g++ encode_and_decode.cpp -o encode_and_decode

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string run; cin >> run;
    if (run == "first") {
        int n; cin >> n;
        string ans = "";
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            x--;
            ans += (x + 'a');
        }
		cout << ans;
    }
    else {
		string s; cin >> s;
		int n = s.length();
		cout << n << "\n";
		for (int i = 0; i < n; i++) {
			cout << s[i] - 'a' + 1;
			if (i != n - 1) cout << ' ';
		}
    }
}