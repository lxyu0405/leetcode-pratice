//
//  easy_MoveZeros.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_MoveZeros_h
#define easy_MoveZeros_h



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && zeroIndex == -1){
                zeroIndex = i;
            }
            if (nums[i] != 0 && zeroIndex != -1) {
                swapArr(i, zeroIndex, nums);
                zeroIndex++;
            }
        }
    }
    
    void swapArr(int a, int b, vector<int> &nums){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    
};

#endif /* easy_MoveZeros_h */
