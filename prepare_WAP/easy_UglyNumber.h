//
//  easy_UglyNumber.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_UglyNumber_h
#define easy_UglyNumber_h

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)    return false;
        if(num == 1)    return true;
        while(num % 2 == 0)
            num /= 2;
        while(num % 3 == 0)
            num /= 3;
        while(num % 5 == 0)
            num /= 5;
        return num == 1 ? true : false;
    }
};

#endif /* easy_UglyNumber_h */
