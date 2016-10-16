//
//  easy_AddDigits.h
//  Cpp-Exam
//
//  Created by luxy on 10/13/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_AddDigits_h
#define easy_AddDigits_h

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        return (num - 1) % 9 + 1;
    }
};

#endif /* easy_AddDigits_h */
