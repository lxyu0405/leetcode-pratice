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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        if (postorder.size() == 0 || inorder.size() == 0) {
            return root;
        }
        int len = postorder.size();
        root = buildTreeCore(inorder, postorder, 0, len-1, 0, len-1);
        return root;
    }
    
    TreeNode* buildTreeCore(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int posStart, int posEnd){
        if(inStart > inEnd || posStart > posEnd){
            return NULL;
        }
        TreeNode* thisRoot;
        int rootVal = postorder[posEnd];
        thisRoot = new TreeNode(rootVal);
        
        if (inStart == inEnd || posStart == posEnd) {
            return thisRoot;
        }
        
        int rootIndexInorder = inStart;
        for (; rootIndexInorder <= inEnd; rootIndexInorder++) {
            if (inorder[rootIndexInorder] == rootVal) {
                break;
            }
        }
        int len = rootIndexInorder - inStart;
        thisRoot->left = buildTreeCore(inorder, postorder, inStart, rootIndexInorder - 1, posStart, posStart + len - 1);
        thisRoot->right = buildTreeCore(inorder, postorder, rootIndexInorder + 1, inEnd, posStart + len, posEnd - 1);
        return thisRoot;
    }
};
