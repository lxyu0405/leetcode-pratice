#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<string>> phoneDigits;
    bool isLegalDigits(char dig){
        return dig >= '2' && dig <= '9' ? true : false;
    }
public:
    Solution(){
        // 2
        phoneDigits.push_back(vector<string>({"a","b","c"}));
        // 3
        phoneDigits.push_back(vector<string>({"d","e","f"}));
        // 4
        phoneDigits.push_back(vector<string>({"g","h","i"}));
        // 5
        phoneDigits.push_back(vector<string>({"j","k","l"}));
        // 6
        phoneDigits.push_back(vector<string>({"m","n","o"}));
        // 7
        phoneDigits.push_back(vector<string>({"p","q","r","s"}));
        // 8
        phoneDigits.push_back(vector<string>({"t","u","v"}));
        // 9
        phoneDigits.push_back(vector<string>({"w","x","y","z"}));
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) {
            return res;
        }
        if (digits.length() == 1 && isLegalDigits(digits[0])) {
            return phoneDigits[digits[0] - '2'];
        }
        if (digits.length() > 1 && isLegalDigits(digits[0])) {
            vector<string> restPart = letterCombinations(digits.substr(1));
            if (restPart.size() != 0) {
                for (auto cha : phoneDigits[digits[0] - '2']) {
                    for (auto restStr : restPart) {
                        res.push_back(cha + restStr);
                    }
                }
            }
        }
        return res;
    }
};
