#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int startIndex = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                startIndex = i;
                break;
            }
        }
        if (isNum(str[startIndex])) {
            res = theNumber(1, str, startIndex);
        }else if(str[startIndex] == '+'){
            res = theNumber(1, str, startIndex+1);
        }else if(str[startIndex] == '-'){
            res = theNumber(-1, str, startIndex+1);
        }
        return (int)res;
    }
    
    long theNumber(int flag, string str, int startIndex){
        long res = 0;
        for (int i = startIndex; i < str.length(); i++) {
            if (isNum(str[i])) {
                res = 10 * res + (str[i] - '0');
                if (flag * res >= INT32_MAX) {
                    return INT32_MAX;
                }
                if (flag * res <= INT32_MIN) {
                    return INT32_MIN;
                }
            }else{
                break;
            }
        }
        return flag * res;
    }
    
    bool isNum(char c){
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
};
