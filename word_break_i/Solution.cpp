#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;

using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> breakable(s.length(),false);
        for (int i = 0; i < s.length(); i++) {
            if (isContain(wordDict, s.substr(0,i+1))) {
                breakable[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (breakable[j] && isContain(wordDict, s.substr(j+1,i-j))) {
                    breakable[i] = true;
                    break;
                }
            }
        }
        return breakable[s.length()-1];
    }
    
    bool isContain(unordered_set<string>& wordDict, string word){
        if (wordDict.find(word) != wordDict.end()) {
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    string s = "leetcode";
    unordered_set<string> wordDict; //"cat", "cats", "and", "sand", "dog"
    
    wordDict.insert("leet");
    wordDict.insert("code");
    
    Solution test;
    cout << test.wordBreak(s, wordDict) << endl;
    return 0;
}

/*
 // DFS [Brutal Force]
 // TLE
 class Solution {
 public:
 bool wordBreak(string s, unordered_set<string>& wordDict) {
 for (int i = s.length()-1; i >= 0; i--) {
 if (isContain(wordDict, s.substr(i))) {
 if (i == 0) {
 return true;
 }
 if (wordBreak(s.substr(0,i), wordDict)) {
 return true;
 }
 }
 }
 return false;
 }
 
 bool isContain(unordered_set<string>& wordDict, string word){
 if (wordDict.find(word) != wordDict.end()) {
 return true;
 }else{
 return false;
 }
 }
 
 };*/

