#include <vector>
#include <string>
#include <map>
using namespace std;
    // I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）
class Solution {
    map<char, int> RomanChar;
public:
    Solution(){
        RomanChar['I'] = 1;
        RomanChar['V'] = 5;
        RomanChar['X'] = 10;
        RomanChar['L'] = 50;
        RomanChar['C'] = 100;
        RomanChar['D'] = 500;
        RomanChar['M'] = 1000;
    }
    
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i == s.length()-1) {
                res += getTheInt(s[i]);
                break;
            }
            int thisR = getTheInt(s[i]);
            int nextR = getTheInt(s[i+1]);
            if (thisR >= nextR) {
                res += thisR;
            }else{
                res += (nextR - thisR);
                i++;
            }
        }
        return res;
    }

    int getTheInt(char c){
        auto thisPair = RomanChar.find(c);
        return thisPair->second;
    }
};

