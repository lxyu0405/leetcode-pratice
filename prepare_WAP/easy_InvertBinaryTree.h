//
//  easy_InvertBinaryTree.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_InvertBinaryTree_h
#define easy_InvertBinaryTree_h

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* tempLeft = root->left;
        root->left = root->right;
        root->right = tempLeft;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

#endif /* easy_InvertBinaryTree_h */
