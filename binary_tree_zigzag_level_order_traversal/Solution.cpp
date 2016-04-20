#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (!root) {    return res; }
        
        queue<stack<TreeNode*>> allTreeNodes;
        
        stack<TreeNode*> firstTreeLevel;
        firstTreeLevel.push(root);
        
        allTreeNodes.push(firstTreeLevel);
        
        bool leftToRight = true;
        while (!allTreeNodes.empty()) {
            stack<TreeNode*> thisTreeLevel = allTreeNodes.front();
            allTreeNodes.pop();
            
            vector<int> thisRes;
            stack<TreeNode*> nextTreeLevel;
            
            while (!thisTreeLevel.empty()) {
                TreeNode* node = thisTreeLevel.top();
                thisTreeLevel.pop();
                thisRes.push_back(node->val);
                addToStack(nextTreeLevel, leftToRight, node);
            }
            
            // push next tree level to the allTreeNodes
            if (!nextTreeLevel.empty()) {
                allTreeNodes.push(nextTreeLevel);
            }
            // switch to another direction
            leftToRight ^= 1;
            // push bach this line result
            res.push_back(thisRes);
        }
        return res;
    }
    
    void addToStack(stack<TreeNode*>& treeLevel, bool leftToRight, TreeNode* node){
        if (leftToRight) {
            if (node->left != NULL) {
                treeLevel.push(node->left);
            }
            if (node->right != NULL) {
                treeLevel.push(node->right);
            }
        }else{
            if (node->right != NULL) {
                treeLevel.push(node->right);
            }
            if (node->left != NULL) {
                treeLevel.push(node->left);
            }
        }
    }
    
    TreeNode* constructTreeFromIntArray(){
        int nums[] = {3,9,20,0,0,15,7};
        vector<int> vecNums(nums,nums+sizeof(nums)/sizeof(int));
        vector<TreeNode*> tree(vecNums.size(), NULL);
        tree[0] = new TreeNode(nums[0]);
        for (int i = 1; i < vecNums.size(); i++) {
            TreeNode* node = NULL;
            if (vecNums[i] != 0) {
                node = new TreeNode(vecNums[i]);
            }
            
            if (i & 1) { // odd
                tree[(i-1)>>1]->left = node;
            }else{ // even
                tree[(i-1)>>1]->right = node;
            }
            tree[i] = node;
        }
        return tree[0];
    }
    
};


int main(){
    Solution test;
    test.zigzagLevelOrder(test.constructTreeFromIntArray());
    return 0;
}
