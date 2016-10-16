//
//  easy_NimGame.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_NimGame_h
#define easy_NimGame_h

class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4 == 0){
            return false;
        }
        return true;
    }
};

#endif /* easy_NimGame_h */
