//
//  easy_LowestCommonAncestorOfABinarySearchTree.h
//  Cpp-Exam
//
//  Created by luxy on 10/15/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_LowestCommonAncestorOfABinarySearchTree_h
#define easy_LowestCommonAncestorOfABinarySearchTree_h

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // make sure p->val < q->val
        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }
        // one of them is root
        if (p == root || q == root) {
            return root;
        }
        // two sides
        if (p->val < root->val && root->val < q->val) {
            return root;
        }
        // right side
        if (p->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // left side
        return lowestCommonAncestor(root->left, p, q);
        
    }
};


#endif /* easy_LowestCommonAncestorOfABinarySearchTree_h */
