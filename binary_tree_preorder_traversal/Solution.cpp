#include <string>
#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> preorderStack;
        preorderStack.push(root);
        while (!preorderStack.empty()) {
            TreeNode* thisNode = preorderStack.top();
            preorderStack.pop();
            if (thisNode->right != NULL) {
                preorderStack.push(thisNode->right);
            }
            if (thisNode->left != NULL) {
                preorderStack.push(thisNode->left);
            }
            res.push_back(thisNode->val);
        }
        return res;
    }
};
