//
//  easy_RansomNode.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_RansomNode_h
#define easy_RansomNode_h


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for (auto c : magazine) {
            umap[c]++;
        }
        for (auto c : ransomNote) {
            umap[c]--;
            if (umap[c] < 0) {
                return false;
            }
        }
        return true;
    }
    
};

#endif /* easy_RansomNode_h */
