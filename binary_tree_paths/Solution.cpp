#include <vector>
#include <unordered_set>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) {
            return res;
        }
        if (root->left == NULL && root->right == NULL) {
            res.push_back(to_string(root->val));
            return res;
        }
        if (root->left != NULL){
            DFSHelper(res, to_string(root->val), root->left);
        }
        if (root->right != NULL){
            DFSHelper(res, to_string(root->val), root->right);
        }
        return res;
    }
private:
    void DFSHelper(vector<string> &res, string path, TreeNode* node){
        if (node->left == NULL && node->right == NULL) {
            res.push_back(path + "->" + to_string(node->val));
            return;
        }
        if (node->left != NULL){
            DFSHelper(res, path + "->" + to_string(node->val), node->left);
        }
        if (node->right != NULL){
            DFSHelper(res, path + "->" + to_string(node->val), node->right);
        }
    }
    
};
