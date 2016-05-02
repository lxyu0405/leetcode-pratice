#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */


typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        if (preorder.size() == 0 || inorder.size() == 0) {
            return root;
        }
        int len = preorder.size();
        root = buildTreeCore(inorder, preorder, 0, len-1, 0, len-1);
        return root;
    }
    
    TreeNode* buildTreeCore(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd){
        if(inStart > inEnd || preStart > preEnd){
            return NULL;
        }
        TreeNode* thisRoot;
        int rootVal = preorder[preStart];
        thisRoot = new TreeNode(rootVal);
        
        if (inStart == inEnd || preStart == preEnd) {
            return thisRoot;
        }
        
        int rootIndexInorder = inStart;
        for (; rootIndexInorder <= inEnd; rootIndexInorder++) {
            if (inorder[rootIndexInorder] == rootVal) {
                break;
            }
        }
        int len = rootIndexInorder - inStart;
        thisRoot->left = buildTreeCore(inorder, preorder, inStart, rootIndexInorder - 1, preStart + 1, preStart + len);
        thisRoot->right = buildTreeCore(inorder, preorder, rootIndexInorder + 1, inEnd, preStart + len + 1, preEnd);
        return thisRoot;
    }
    
};
