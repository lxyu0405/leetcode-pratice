#include <vector>
#include <iostream>

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
    ListNode* reverseListLi(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* thisNode = head;
        ListNode* preNode = NULL;
        ListNode* tempThis = NULL;
        while (thisNode != NULL) {
            tempThis = thisNode;
            
            // go to next node first
            thisNode = thisNode->next;
            // reverse
            tempThis->next = preNode;
            
            preNode = tempThis;
        }
        return preNode;
    }
    
    // recursive
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* reverseHead = NULL;
        ListNode* restTail = reverseHelper(head->next, &reverseHead);
        restTail->next = head;
        head->next = NULL;
        return reverseHead;
    }
    
    ListNode* reverseHelper(ListNode* node, ListNode** reverseHead){
        if (node->next == NULL) {
            *reverseHead = node;
            return node;
        }
        ListNode* restTail = reverseHelper(node->next, reverseHead);
        restTail->next = node;
        return node;
    }
};
