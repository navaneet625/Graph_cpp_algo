#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isLastChar;

    TrieNode() { 
        isLastChar = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, string &s) {
    TrieNode* node = root;
    for (auto ch : s) {
        int idx = ch - 'a';
        if (!node->children[idx]) {
            node->children[idx] = new TrieNode();
        }
        node = node->children[idx];
    }
    node->isLastChar = true;
}

bool search(TrieNode* root, string &s) {
    TrieNode* node = root;
    for (auto ch : s) {
        int idx = ch - 'a';
        if (!node->children[idx]) return false;
        node = node->children[idx];
    }
    return node->isLastChar;
}

bool prefix(TrieNode* root, string &s) {
    TrieNode* node = root;
    for (auto ch : s) {
        int idx = ch - 'a';
        if (!node->children[idx]) return false;
        node = node->children[idx];
    }
    return true;
}

void freeTrie(TrieNode* node) {
    if (node) {
        for (int i = 0; i < 26; i++) {
            freeTrie(node->children[i]);
        }
        delete node;
    }
}

int main() {
    TrieNode* root = new TrieNode();

    int n;
    string s;

    // Input number of words
    cin >> n;

    // Insert each word into the Trie
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert(root, s);
    }

    // Search for a word in the Trie
    cin >> s;
    cout << (search(root, s) ? "Found" : "Not Found") << "\n";

    // Check if a prefix exists in the Trie
    cin >> s;
    cout << (prefix(root, s) ? "Prefix Exists" : "Prefix Not Found") << "\n";

    // Free Trie memory
    freeTrie(root);

    return 0;
}