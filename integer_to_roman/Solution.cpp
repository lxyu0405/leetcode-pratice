#include <string>
using namespace std;

class Solution {

public:
    string intToRoman(int num) {
        // 1 ~ 3999
        string res = "";
        int thousand = num / 1000;
        int hundred = (num % 1000) / 100;
        int ten = (num % 100) / 10;
        int one = num % 10;
        
        for (int i = 0; i < thousand; i++){
            res += "M";
        }
        res += getDecresRoman(hundred, "C", "D", "M");
        res += getDecresRoman(ten, "X", "L", "C");
        res += getDecresRoman(one, "I", "V", "X");
        return res;
    }
    
    string getDecresRoman(int num, string one, string half, string full){
        string res = "";
        switch (num) {
            case 1:
            case 2:
            case 3:
                for (int i = 0; i < num; i++) {
                    res += one;
                }
                break;
            case 4:
                res += (one + half);
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                res += half;
                for (int i = 0; i < num-5; i++) {
                    res += one;
                }
                break;
            case 9:
                res += (one + full);
                break;
            default:
                break;
        }
        return res;
    }
};
