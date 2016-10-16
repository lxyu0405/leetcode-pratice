//
//  easy_PowerOfTwo.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_PowerOfTwo_h
#define easy_PowerOfTwo_h

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 1){
            if(n & 1)
                return false;
            n >>= 1;
        }
        return n == 1 ? true : false;
    }
};

#endif /* easy_PowerOfTwo_h */
