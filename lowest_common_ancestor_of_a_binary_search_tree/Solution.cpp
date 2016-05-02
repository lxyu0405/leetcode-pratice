#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // make sure p->val < q->val
        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }
        // one of p and q is root
        if (p == root || q == root) {
            return root;
        }
        // p and q locate at two sides of root
        if (p->val < root->val && q->val > root->val) {
            return root;
        }
        // both p and q are at the left side of the root
        if (q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // both p and q are at the right side of the root
        return lowestCommonAncestor(root->right, p, q);
    }
};
