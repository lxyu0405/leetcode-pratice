#include <string>
#include <vector>
#include <unordered_set>
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
    ListNode *getIntersectionNodeSet(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> listA;
        // add listA's node to the set
        ListNode *pA = headA;
        while (pA != NULL) {
            listA.insert(pA);
            pA = pA->next;
        }
        // find intersection
        ListNode *pB = headB;
        while (pB != NULL) {
            if (listA.count(pB)) {
                return pB;
            }
            pB = pB->next;
        }
        return NULL;
    }
    
    // two pointers
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int lengthA = 0, lengthB = 0;
        while (pA != NULL || pB != NULL) {
            if (pA != NULL) {
                lengthA++;
                pA = pA->next;
            }
            if (pB != NULL) {
                lengthB++;
                pB = pB->next;
            }
        }
        return getIntersection(headA, headB, lengthA, lengthB);
    }
private:
    ListNode *getIntersection(ListNode *headA, ListNode *headB, int lengthA, int lengthB){
        // make sure lengthA >= length B
        if (lengthA < lengthB) {
            return getIntersection(headB, headA, lengthB, lengthA);
        }
        int lengthGap = lengthA - lengthB;
        for (int i = 0; i < lengthGap; i++) {
            headA = headA->next;
        }
        // now lengthA == lengthB
        ListNode *pA = headA, *pB = headB;
        while (pA != NULL && pB != NULL) {
            if (pA == pB) {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};
