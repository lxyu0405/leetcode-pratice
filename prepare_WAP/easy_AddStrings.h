//
//  easy_AddStrings.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_AddStrings_h
#define easy_AddStrings_h

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        // make sure num1.length() >= num2.length()
        if (num2.length() > num1.length()) {
            return addStrings(num2, num1);
        }
        
        // s1: "12345", s2: "234"
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> sumArr(num1.length()+1, 0);
        for(int i = 0; i < num1.length(); i++){
            if(i > num2.length()-1){
                sumArr[i] = (int)num1[i]-'0';
            }else{
                sumArr[i] = (int)(num2[i]-'0') + (int)(num1[i]-'0');
            }
        }
        
        int carry = 0;
        for (int i = 0; i < sumArr.size(); i++) {
            int tempNum = sumArr[i] + carry;
            sumArr[i] = tempNum % 10;
            carry = tempNum / 10;
        }
        
        string res = "";
        bool start = false;
        for (int i = sumArr.size()-1; i >= 0; i--) {
            if (sumArr[i] != 0) {
                start = true;
                res += (char)(sumArr[i]+'0');
            }
            if (sumArr[i] == 0 && start){
                res += "0";
            }
        }
        
        return res.size() == 0 ? "0" : res;    }
};


#endif /* easy_AddStrings_h */
