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
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int heightLeft = height(root->left);
        int heightRight = height(root->right);
        if (heightLeft == heightRight) {
            return (1 << heightLeft) + countNodes(root->right);
        }else{
            return (1 << heightRight) + countNodes(root->left);
        }
    }
private:
    int height(TreeNode* root){
        return root == NULL ? 0 : 1 + height(root->left);
    }
};
