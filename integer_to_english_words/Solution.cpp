#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
    map<int, string> numToEng;
public:
    
    Solution(){
        // ***
        numToEng[1] = "One";
        numToEng[2] = "Two";
        numToEng[3] = "Three";
        numToEng[4] = "Four";
        numToEng[5] = "Five";
        numToEng[6] = "Six";
        numToEng[7] = "Seven";
        numToEng[8] = "Eight";
        numToEng[9] = "Nine";
        numToEng[10] = "Ten";
        //  ***
        numToEng[11] = "Eleven";
        numToEng[12] = "Twelve";
        numToEng[13] = "Thirteen";
        numToEng[14] = "Fourteen";
        numToEng[15] = "Fifteen";
        numToEng[16] = "Sixteen";
        numToEng[17] = "Seventeen";
        numToEng[18] = "Eighteen";
        numToEng[19] = "Nineteen";
        //  ***
        numToEng[20] = "Twenty";
        numToEng[30] = "Thirty";
        numToEng[40] = "Forty";
        numToEng[50] = "Fifty";
        numToEng[60] = "Sixty";
        numToEng[70] = "Seventy";
        numToEng[80] = "Eighty";
        numToEng[90] = "Ninety";
    }
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string res = "";
        int billion = num / 1000000000;
        int million = (num % 1000000000) / 1000000;
        int thousand = (num % 1000000) / 1000;
        int one = num % 1000;
        
        if (billion != 0) {
            res += numberToWordsEachPart(" Billion", billion);
        }
        if (million != 0) {
            res += (res.size() == 0 ? numberToWordsEachPart(" Million", million) : (" " + numberToWordsEachPart(" Million", million)));
        }
        if (thousand != 0) {
            res += (res.size() == 0 ? numberToWordsEachPart(" Thousand", thousand) : (" " + numberToWordsEachPart(" Thousand", thousand)));
        }
        if (one != 0) {
            res += (res.size() == 0 ? numberToWordsEachPart("", one) : (" " + numberToWordsEachPart("", one)));
        }
        
        return res;
    }
    
    string numberToWordsEachPart(string scales, int num){
        string res = "";
        if (num == 0) {
            return res;
        }
        int hundred = num / 100;
        int ten = (num % 100) / 10;
        int one = num % 10;
        if (hundred != 0) {
            res += getEngFromInt(hundred) + " Hundred";
        }
        if (ten == 1) {
            int restNum = num % 100;
            res += (res.size() == 0 ? getEngFromInt(restNum) : (" " + getEngFromInt(restNum)));
        }
        if (ten > 1) {
            res += (res.size() == 0 ? getEngFromInt(ten*10) : (" " + getEngFromInt(ten*10)));
        }
        if (one != 0 && ten != 1) {
            res += (res.size() == 0 ? getEngFromInt(one) : (" " + getEngFromInt(one)));
        }
        return res + scales;
    }
    
    string getEngFromInt(int num){
        auto res = numToEng.find(num);
        return res->second;
    }
};

