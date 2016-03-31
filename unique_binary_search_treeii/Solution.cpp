#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) {
            return vector<TreeNode*> (NULL);
        }
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int left, int right){
        vector<TreeNode*> allTrees;
        if (left > right) {
            allTrees.push_back(NULL);
            return allTrees;
        }
        if (left == right) {
            TreeNode *leaveNode = new TreeNode(left);
            allTrees.push_back(leaveNode);
            return allTrees;
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftTree = generate(left, i-1);
            vector<TreeNode*> rightTree = generate(i+1, right);
            for (int li = 0; li < leftTree.size(); li++) {
                for (int ri = 0; ri < rightTree.size(); ri++) {
                    TreeNode *thisTree = new TreeNode(i);
                    thisTree->left = leftTree[li];
                    thisTree->right = rightTree[ri];
                    allTrees.push_back(thisTree);
                }
            }
        }
        return allTrees;
    }
};

