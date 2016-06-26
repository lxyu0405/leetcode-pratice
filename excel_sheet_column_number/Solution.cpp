#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            res = res * 26 + getIntFromChar(s[i]);
        }
        return res;
    }
    
private:
    int getIntFromChar(char c){
        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 1;
        }else{
            // a ~ z
            return c - 'a' + 1;
        }
    }
    
};
