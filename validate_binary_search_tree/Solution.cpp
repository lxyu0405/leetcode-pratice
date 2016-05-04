#include <vector>
#include <string>
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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isValidBSTCore(root->left, LONG_LONG_MIN, root->val) && isValidBSTCore(root->right, root->val, LONG_LONG_MAX);
    }
private:
    bool isValidBSTCore(TreeNode* node, long begin, long end){
        if (node == NULL) {
            return true;
        }
        if (node->val <= begin || node->val >= end) {
            return false;
        }else{
            return isValidBSTCore(node->left, begin, node->val) && isValidBSTCore(node->right, node->val, end);
        }
    }
};
