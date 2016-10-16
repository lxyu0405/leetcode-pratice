//
//  easy_LongestPalindrome.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_LongestPalindrome_h
#define easy_LongestPalindrome_h


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> umap;
        for (auto c : s) {
            umap[c]++;
        }
        bool hasOdd = false;
        int pairSize = 0;
        for (auto p : umap) {
            pairSize += p.second/2;
            if (p.second & 1) {
                hasOdd = true;
            }
        }
        if (hasOdd) {
            return (pairSize << 1) + 1;
        }else{
            return pairSize << 1;
        }
    }
    
    
};

#endif /* easy_LongestPalindrome_h */
