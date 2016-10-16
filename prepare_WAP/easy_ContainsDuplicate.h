//
//  easy_ContainsDuplicate.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_ContainsDuplicate_h
#define easy_ContainsDuplicate_h

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0)    return false;
        unordered_set<int> uset(nums.begin(), nums.end());
        return uset.size() != nums.size();
    }
};


#endif /* easy_ContainsDuplicate_h */
