#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 */
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

/**
 * Definition for a binary tree node.
 */
typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode* median = getListMedian(head, NULL);
        TreeNode* root = new TreeNode(median->val);
        root->left = constructTree(head, median);
        root->right = constructTree(median->next, NULL);
        return root;
    }
    TreeNode* constructTree(ListNode* start, ListNode* end){
        if (start == NULL || start == end) {
            return NULL;
        }
        if (start->next == end) {
            return new TreeNode(start->val);
        }
        ListNode* median = getListMedian(start, end);
        TreeNode* newTreeNode = new TreeNode(median->val);
        newTreeNode->left = constructTree(start, median);
        newTreeNode->right = constructTree(median->next, end);
        return newTreeNode;
    }
    
    ListNode* getListMedian(ListNode* start, ListNode* end){
        ListNode* slow = start;
        ListNode* fast = start;
        while(fast->next != end && fast->next->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next == end) {
            return slow;
        }else{
            // fast->next->next == end
            return slow->next;
        }
    }
    void levelOrderTraverse(TreeNode* root){
        queue<TreeNode*> newQueue;
        newQueue.push(root);
        while (!newQueue.empty()) {
            TreeNode* thisNode = newQueue.front();
            newQueue.pop();
            cout << thisNode->val << " ";
            if (thisNode->left != NULL) {
                newQueue.push(thisNode->left);
            }
            if (thisNode->right != NULL) {
                newQueue.push(thisNode->right);
            }
        }
        cout << endl;
    }
};



int main(){
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int array[] = {1,2,3,4,5,6,7,8,9,10,12,15,17,22,26,30};
    for (int* p = array; p < array + sizeof(array)/sizeof(int); p++) {
        ListNode* newListNode = new ListNode(*p);
        if (head == NULL) {
            tail = head = newListNode;
        }else{
            tail->next = newListNode;
            tail = newListNode;
        }
    }
    Solution test;
    test.levelOrderTraverse(test.sortedListToBST(head));
    return 0;
}
