//
//  easy_LinkedListCycle.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_LinkedListCycle_h
#define easy_LinkedListCycle_h

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *pSlow = head, *pFast = head;
        while (pFast->next != NULL && pFast->next->next != NULL) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pSlow == pFast) {
                return true;
            }
        }
        return false;
    }
};

#endif /* easy_LinkedListCycle_h */
