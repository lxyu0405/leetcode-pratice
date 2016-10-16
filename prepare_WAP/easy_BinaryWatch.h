//
//  easy_BinaryWatch.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_BinaryWatch_h
#define easy_BinaryWatch_h

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
    vector<string> readBinaryWatch(int num) {
        vector<string> allTime;
        
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                int thisNum = (h << 6) + m;
                if (bitset<10>(thisNum).count() == num) {
                    string minute = to_string(m);
                    if (minute.length() == 1) {
                        minute = "0" + minute;
                    }
                    allTime.push_back(to_string(h) + ":" + minute);
                }
            }
        }
        return allTime;
    }
};

#endif /* easy_BinaryWatch_h */
