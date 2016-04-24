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
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        
        ListNode* preDelete = fakeHead;
        ListNode* now = head;
        while (now->next != NULL) {
            if(preDelete->next->val == now->next->val) {
                while (now->next != NULL && preDelete->next->val == now->next->val) {
                    now = now->next;
                }
                preDelete->next = now->next;
            }else{
                preDelete = preDelete->next;
            }
            now = now->next == NULL ? now : now->next;
        }
        
        return fakeHead->next;
    }
};
