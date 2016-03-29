#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

using std::cin;
using std::cout;
using std::endl;



class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<string>> allPossSetens;
        
        for (int i = 0; i < s.length(); i++) {
            vector<string> possSetens;
            string beginWord = s.substr(0,i+1);
            if (isContain(wordDict, beginWord)) {
                possSetens.push_back(beginWord);
            }
            for (int j = 0; j < i; j++) {
                vector<string> preSetens = allPossSetens[j];
                string thisPossWord = s.substr(j+1,i-j);
                if (isContain(wordDict, thisPossWord) && preSetens.size() != 0) {
                    for (int k = 0; k < preSetens.size(); k++) {
                        possSetens.push_back(preSetens[k] + " " + thisPossWord);
                    }
                }
            }
            
            allPossSetens.push_back(possSetens);
            
        }
        return allPossSetens[s.length()-1];
    }
    
    bool isContain(unordered_set<string>& wordDict, string word){
        if (wordDict.find(word) != wordDict.end()) {
            return true;
        }else{
            return false;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> wordDict; //"cat", "cats", "and", "sand", "dog"
    wordDict.insert("a");
    wordDict.insert("aa");
    wordDict.insert("aaa");
    wordDict.insert("aaaa");
    wordDict.insert("aaaaa");
    wordDict.insert("aaaaaa");
    wordDict.insert("aaaaaaa");
    wordDict.insert("aaaaaaaa");
    wordDict.insert("aaaaaaaaa");
    wordDict.insert("aaaaaaaaaa");
    
    Solution test;
    vector<string> res = test.wordBreak(s, wordDict);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
