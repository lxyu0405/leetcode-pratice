#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* pre = head;
        ListNode* now = head->next;
        while (now != NULL) {
            if (pre->val == now->val) {
                pre->next = now->next;
            }else{
                pre = now;
            }
            now = now->next;
        }
        return head;
    }
};
