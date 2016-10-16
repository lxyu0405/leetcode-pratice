//
//  easy_RotateArray.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_RotateArray_h
#define easy_RotateArray_h

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotateNum = k % nums.size();
        if (rotateNum == 0) {
            return;
        }
        reverse(nums.begin(), nums.begin() + nums.size() - rotateNum - 1);
        reverse(nums.begin() + nums.size() - rotateNum, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

#endif /* easy_RotateArray_h */
