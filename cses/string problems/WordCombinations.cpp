#include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
        TrieNode* children[26];
        bool eow;

        TrieNode() {
            eow = false;
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }

        void insert(string word) {
            TrieNode* curr = this;
            for(int i = 0; i < word.size(); i++) {
                if (!(curr->children[word[i]- 'a'])) {
                    curr->children[word[i] - 'a'] = new TrieNode();
                }
                curr = curr->children[word[i] - 'a'];
            }
            curr->eow = true;
        }
};

TrieNode* trie = new TrieNode();
string s;
long long k;
long long MOD = 1000000007LL;

unordered_map<long long, long long> cache;

long long dfs(int i) {
    if (cache.find(i) != cache.end()) {
        return cache[i];
    } else if (i == s.size()) {
        cache[i] = 1;
    } else if (i > s.size()) {
        cache[i] = 0;
    } else {
        // iterate through string starting at position i, see if any prefixes exist via the trie
        TrieNode* curr = trie;
        for(int j = i; j < s.size(); j++) {
            curr = curr->children[s[j] - 'a'];
            if (!curr) {
                break;
            }
            if (curr->eow) {
                cache[i] += dfs(j + 1);
            }
        }
        cache[i] %= MOD;
    }
    return cache[i];
}

int  main() {
    cin >> s;
    cin >> k;
    for(int i = 0; i < k; i++) {
        string line;
        cin >> line;
        (*trie).insert(line);
    }
    cout << dfs(0);
    return 0;
}