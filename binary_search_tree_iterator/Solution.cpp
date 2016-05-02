#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode*> minTreeNode;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* p = root;
        while (p != NULL) {
            minTreeNode.push(p);
            p = p->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !minTreeNode.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* thisMinNode = minTreeNode.top();
        minTreeNode.pop();
        if (thisMinNode->right != NULL) {
            TreeNode* p = thisMinNode->right;
            while (p != NULL) {
                minTreeNode.push(p);
                p = p->left;
            }
        }
        return thisMinNode->val;
    }
};
