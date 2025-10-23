#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Get-Content t.txt | .\f.exe

struct Trie {
    struct TrieNode {
        TrieNode* c[26];
        string shortestWord = "";    //true if a word ends on this node
        int numWords = 0;   //counts how many words use this node as prefix
    };
 
    TrieNode head;
 
    Trie() {
        this->head = TrieNode();
    }
 
    void insert(string s){
        TrieNode* ptr = &head;
        for(int i = 0; i < s.length(); i++){
            ptr->numWords ++;
            int ch = s[i] - 'a';
            if(ptr->c[ch] == nullptr) {
                ptr->c[ch] = new TrieNode();
            }
            ptr = ptr->c[ch];
        }
        ptr->numWords ++;
        if (ptr->shortestWord == "") {
            if (ptr->shortestWord.length() > s.length()) ptr->shortestWord = s;
        }
    }
 
    TrieNode* query(string s) {
        TrieNode* ptr = &head;
        for(int i = 0; i < s.length(); i++){
            int ch = s[i] - 'a';
            ptr = ptr->c[ch];
            if(ptr == nullptr) {
                break;
            }
        }
        return ptr;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    Trie t;
    while (s != "\n") {
        t.insert(reverse(s.begin(), s.end()));
    }
    cin >> s;
    while (s != "\n") {
        Trie::TrieNode* node = &trie.head;
        // so the answer is walk down the word, store the smallest word at the index instead of if its a node
        // simply walk all the way down and if we have a correct word
        string curr = "";
        Trie::TrieNode* node = &trie.head;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (!node->c[s[j - 1] - 'a']) {

            }
        }
        cout << reverse(curr.begin(), curr.end()) << "\n";
        cin >> s;
    }

}