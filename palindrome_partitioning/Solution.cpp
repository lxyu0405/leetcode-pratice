#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> oneRes;
        findPartitions(s, 0, res, oneRes);
        return res;
    }
private:
    void findPartitions(const string words, int start, vector<vector<string>>& res, vector<string> oneRes){
        if (start == words.length()) {
            res.push_back(oneRes);
            return;
        }
        for (int i = start; i < words.length(); i++) {
            string thisWord = words.substr(start, i-start+1);
            if (isPalindrome(thisWord)) {
                oneRes.push_back(thisWord);
                findPartitions(words, i+1, res, oneRes);
                oneRes.pop_back();
            }
        }
    }
    bool isPalindrome(string sub){
        if (sub.length() == 1) {
            return true;
        }
        for (int i = 0; i < sub.length()/2; i++) {
            if (sub[i] != sub[sub.length()-1-i]) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution test;
    test.partition("a");
    return 0;
}
