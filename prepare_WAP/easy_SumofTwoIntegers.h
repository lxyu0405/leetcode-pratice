//
//  easy_SumofTwoIntegers.h
//  Cpp-Exam
//
//  Created by luxy on 10/12/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_SumofTwoIntegers_h
#define easy_SumofTwoIntegers_h

class Solution {
public:
    int getSum(int a, int b) {
        long sum = (long)a + (long)b;
        if(sum > INT16_MAX){
            return INT16_MAX;
        }
        if(sum < INT16_MIN){
            return INT16_MIN;
        }
        return (int)sum;
    }
};


#endif /* easy_SumofTwoIntegers_h */
