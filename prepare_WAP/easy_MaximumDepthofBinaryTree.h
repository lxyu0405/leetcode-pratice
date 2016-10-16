//
//  easy_MaximumDepthofBinaryTree.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_MaximumDepthofBinaryTree_h
#define easy_MaximumDepthofBinaryTree_h

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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int maxLeftDepth = maxDepth(root->left);
        int maxRightDepth = maxDepth(root->right);
        return maxLeftDepth > maxRightDepth ? maxLeftDepth + 1 : maxRightDepth + 1;
    }
};

#endif /* easy_MaximumDepthofBinaryTree_h */
