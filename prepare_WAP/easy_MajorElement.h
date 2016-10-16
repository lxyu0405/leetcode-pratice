//
//  easy_MajorElement.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_MajorElement_h
#define easy_MajorElement_h

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
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int majorEle = nums[0];
        int majorCnt = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == majorEle) {
                majorCnt++;
            }else{
                if (--majorCnt == 0) {
                    majorEle = nums[i];
                    majorCnt = 1;
                }
            }
        }
        
        return majorEle;
    }
};


#endif /* easy_MajorElement_h */
