//
//  easy_ExcelSheetColumnNumber.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_ExcelSheetColumnNumber_h
#define easy_ExcelSheetColumnNumber_h

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            res = res * 26 + (int)(s[i]-'A'+1);
        }
        return res;
    }
};

#endif /* easy_ExcelSheetColumnNumber_h */
