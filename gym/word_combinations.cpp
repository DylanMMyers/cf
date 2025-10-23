#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\word_combinations.exe

int MOD = 1e9 + 7;

struct Trie {
    struct TrieNode {
        TrieNode* c[26];
        bool isWord = false;    //true if a word ends on this node
        int numWords = 0;   //counts how many words use this node as prefix
    };

    TrieNode head;

    Trie() {
        this->head = TrieNode();
    }

    void insert(string s){
        TrieNode* ptr = &head;
        for(int i = 0; i < s.size(); i++){
            ptr->numWords ++;
            int ch = s[i] - 'a';
            if(ptr->c[ch] == nullptr) {
                ptr->c[ch] = new TrieNode();
            }
            ptr = ptr->c[ch];
        }
        ptr->numWords ++;
        ptr->isWord = true;
    }

    TrieNode* query(string s) {
        TrieNode* ptr = &head;
        for(int i = 0; i < s.size(); i++){
            int ch = s[i] - 'a';
            ptr = ptr->c[ch];
            if(ptr == nullptr) {
                break;
            }
        }
        return ptr;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> v(k);
    TrieNode* root = new TrieNode();
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());
        insertKey(root, v[i]);
    }
    ll ans = 0;
    vector<int> dp(n + 1);
    
    cout << ans << "\n";
}