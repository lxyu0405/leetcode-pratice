//
//  easy_IntersectionOfTwoArraysII.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_IntersectionOfTwoArraysII_h
#define easy_IntersectionOfTwoArraysII_h

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> umap;
        for (auto num : nums1) {
            umap[num]++;
        }
        
        for (auto num : nums2) {
            umap[num]--;
            if (umap[num] >= 0) {
                res.push_back(num);
            }
        }
        return res;
    }
};

#endif /* easy_IntersectionOfTwoArraysII_h */
