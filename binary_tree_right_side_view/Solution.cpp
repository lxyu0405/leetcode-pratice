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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        vector<TreeNode*> thisLevel;
        vector<TreeNode*> nextLevel;
        thisLevel.push_back(root);
        while (thisLevel.size() > 0) {
            res.push_back(thisLevel.back()->val);
            for (auto node: thisLevel) {
                if (node->left != NULL) {
                    nextLevel.push_back(node->left);
                }
                if (node->right != NULL) {
                    nextLevel.push_back(node->right);
                }
            }
            thisLevel.clear();
            swap(thisLevel, nextLevel);
        }
        return res;
    }
};

