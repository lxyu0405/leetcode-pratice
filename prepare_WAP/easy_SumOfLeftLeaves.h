//
//  easy_SumOfLeftLeaves.h
//  Cpp-Exam
//
//  Created by luxy on 10/13/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_SumOfLeftLeaves_h
#define easy_SumOfLeftLeaves_h

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

#endif /* easy_SumOfLeftLeaves_h */
