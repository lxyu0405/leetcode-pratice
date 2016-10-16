//
//  easy_PowerOfFour.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_PowerOfFour_h
#define easy_PowerOfFour_h

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
    bool isPowerOfFour(int num) {
        return (num & (num-1)) == 0 && ((num & 0xAAAAAAAA) == 0) && num > 0;
    }
};

#endif /* easy_PowerOfFour_h */
