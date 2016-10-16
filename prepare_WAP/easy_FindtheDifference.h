//
//  easy_findtheDifference.h
//  Cpp-Exam
//
//  Created by luxy on 10/13/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_findtheDifference_h
#define easy_findtheDifference_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> origin;
        for (auto c : s) {
            origin[c]++;
        }
        char res = ' ';
        for (auto c : t) {
            if (--origin[c] < 0) {
                res = c;
                break;
            }
        }
        return res;
    }
};

#endif /* easy_findtheDifference_h */
