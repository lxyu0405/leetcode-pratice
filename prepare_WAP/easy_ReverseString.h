//
//  easy_ReverseString.h
//  Cpp-Exam
//
//  Created by luxy on 10/12/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_ReverseString_h
#define easy_ReverseString_h

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string &s) {
        int start = 0, end = s.length()-1;
        char temp = ' ';
        while (start < end) {
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }
};

#endif /* easy_ReverseString_h */
