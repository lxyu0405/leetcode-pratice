//
//  easy_DeleteNodeInALinkedList.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_DeleteNodeInALinkedList_h
#define easy_DeleteNodeInALinkedList_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 覆盖当前节点值，删除后一节点
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

#endif /* easy_DeleteNodeInALinkedList_h */
