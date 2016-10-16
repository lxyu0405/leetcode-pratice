//
//  easy_FirstUniqueCharacterInAString.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_FirstUniqueCharacterInAString_h
#define easy_FirstUniqueCharacterInAString_h

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap;
        for(auto c : s){
            umap[c]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(umap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

#endif /* easy_FirstUniqueCharacterInAString_h */
