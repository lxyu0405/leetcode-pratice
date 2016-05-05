#include <iostream>

using namespace std;

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
    
    TrieNode* getRoot(){
        return this->root;
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
    
    bool searchPattern(string word, TrieNode* thisRoot) {
        TrieNode* thisTrieNode = thisRoot;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (thisTrieNode->trieChild[j] != NULL){
                        if (i == word.length() - 1 && thisTrieNode->trieChild[j]->wordEnd) {
                            return true;
                        }
                        if (searchPattern(word.substr(i + 1), thisTrieNode->trieChild[j])) {
                            return true;
                        }
                    }
                }
                return false;
            }else{
                // a-z
                if (thisTrieNode->trieChild[word[i] - 'a'] == NULL) {
                    return false;
                }
                thisTrieNode = thisTrieNode->trieChild[word[i] - 'a'];
            }
        }
        return thisTrieNode->wordEnd;
    }
    
private:
    TrieNode* root;
};



class WordDictionary {
public:
    WordDictionary(){
        trieTree = new Trie();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        trieTree->insert(word);
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trieTree->searchPattern(word, trieTree->getRoot());
    }
private:
    Trie *trieTree;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


int main(){
    WordDictionary test;
    test.addWord("a");
    test.addWord("ab");
    cout << test.search("a") << endl;
    cout << test.search("ab") << endl;
    cout << test.search(".a") << endl;
    cout << test.search(".b") << endl;
    cout << test.search("ab.") << endl;
    cout << test.search(".") << endl;
    cout << test.search("..") << endl;
    return 0;
}
