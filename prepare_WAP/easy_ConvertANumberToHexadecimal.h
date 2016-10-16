//
//  easy_ConvertANumberToHexadecimal.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_ConvertANumberToHexadecimal_h
#define easy_ConvertANumberToHexadecimal_h

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        unsigned int n = (unsigned int)num;
        if (n == 0) {
            return "0";
        }
        string res = "";
        while (n > 0) {
            int thisNum = n % 16;
            if (thisNum < 10) {
                // 0- 9
                char thisChar = '0' + thisNum;
                res = thisChar + res;
            }else{
                // 10-15
                char thisChar = 'a' + thisNum - 10;
                res = thisChar + res;
            }
            n /= 16;
        }
        return res;
    }
};


#endif /* easy_ConvertANumberToHexadecimal_h */
