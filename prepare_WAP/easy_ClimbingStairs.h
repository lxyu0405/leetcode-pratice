//
//  easy_ClimbingStairs.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_ClimbingStairs_h
#define easy_ClimbingStairs_h


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
    int climbStairs(int n) {
        vector<int> dpStairs(n+3, 0);
        dpStairs[1] = 1, dpStairs[2] = 2;
        for(int i = 3; i <= n; i++){
            dpStairs[i] = dpStairs[i-1] + dpStairs[i-2];
        }
        return dpStairs[n];
    }
};

#endif /* easy_ClimbingStairs_h */
