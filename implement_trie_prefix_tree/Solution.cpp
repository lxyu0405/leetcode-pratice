class TrieNode {
public:
    bool wordEnd;
    TrieNode* trieChild[26];
    // Initialize your data structure here.
    TrieNode() {
        wordEnd = false;
        memset(trieChild, 0, sizeof(trieChild));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* thisTrieNode = root;
        for (int i = 0; i < word.length(); i++) {
            int thisIndex = word[i] - 'a';
            if (thisTrieNode->trieChild[thisIndex] == NULL) {
                thisTrieNode->trieChild[thisIndex] = new TrieNode();
            }
            thisTrieNode = thisTrieNode->trieChild[thisIndex];
        }
        thisTrieNode->wordEnd = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* thisTrieNode = root;
        for (int i = 0; i < word.length(); i++) {
            int thisIndex = word[i] - 'a';
            if (thisTrieNode->trieChild[thisIndex] == NULL) {
                return false;
            }
            thisTrieNode = thisTrieNode->trieChild[thisIndex];
        }
        return thisTrieNode->wordEnd;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* thisTrieNode = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (thisTrieNode->trieChild[prefix[i]-'a'] == NULL) {
                return false;
            }
            thisTrieNode = thisTrieNode->trieChild[prefix[i]-'a'];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

