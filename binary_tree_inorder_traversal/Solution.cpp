#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        // inorderRecur(root, res);
        inorderItera(root, res);
        return res;
    }
    
    void inorderRecur(TreeNode* root, vector<int>& res){
        if (root == NULL) {
            return;
        }
        inorderRecur(root->left, res);
        res.push_back(root->val);
        inorderRecur(root->right, res);
    }
    
    void inorderItera(TreeNode* root, vector<int>& res){
        stack<TreeNode*> inorderStack;
        inorderStack.push(root);
        while (!inorderStack.empty()) {
            TreeNode* thisNode = inorderStack.top();
            TreeNode* leftTemp = thisNode->left;
            inorderStack.pop();
            if (thisNode->right != NULL) {
                inorderStack.push(thisNode->right);
            }
            if (thisNode->left == NULL && thisNode->right == NULL) {
                res.push_back(thisNode->val);
            }else{
                thisNode->left = NULL, thisNode->right = NULL;
                inorderStack.push(thisNode);
            }
            if (leftTemp != NULL) {
                inorderStack.push(leftTemp);
            }
        }
    }
    
};
