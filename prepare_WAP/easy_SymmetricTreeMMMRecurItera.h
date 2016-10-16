//
//  easy_SymmetricTreeMMMRecurItera.h
//  Cpp-Exam
//
//  Created by luxy on 10/14/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef easy_SymmetricTreeMMMRecurItera_h
#define easy_SymmetricTreeMMMRecurItera_h

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
    // recursive method
    bool isSymmetricRecurHelper(TreeNode* leftNode, TreeNode* rightNode){
        if (leftNode == NULL && rightNode == NULL) {
            return true;
        }
        
        if (leftNode != NULL && rightNode != NULL && leftNode->val == rightNode->val) {
            return isSymmetricRecurHelper(leftNode->left, rightNode->right) && isSymmetricRecurHelper(leftNode->right, rightNode->left);
        }
        return false;
    }
    
    bool isSymmetricRecur(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSymmetricRecurHelper(root->left, root->right);
    }
    
    // iterative method
    bool checkSymmetric(vector<TreeNode*> &lvlArr){
        // odd
        if (lvlArr.size() & 1) {
            return false;
        }
        int start = 0, end = lvlArr.size()-1;
        while (start < end) {
            if ((lvlArr[start] == NULL && lvlArr[end] == NULL) ||\
                (lvlArr[start] != NULL && lvlArr[end] != NULL && lvlArr[start]->val == lvlArr[end]->val)) {
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root){
        if (root == NULL) {
            return true;
        }
        queue<queue<TreeNode*>> lvlOrderTree;
        queue<TreeNode*> thisLvl;
        thisLvl.push(root);
        lvlOrderTree.push(thisLvl);
        
        // level order store
        while (!lvlOrderTree.empty()) {
            queue<TreeNode*> tempLvl = lvlOrderTree.front();
            lvlOrderTree.pop();
            
            queue<TreeNode*> newLvl;
            vector<TreeNode*> newLvlArr;
            while (!tempLvl.empty()) {
                auto node = tempLvl.front();
                tempLvl.pop();
                
                if (node->left != NULL) {
                    newLvl.push(node->left);
                }
                if (node->right != NULL) {
                    newLvl.push(node->right);
                }
                
                newLvlArr.push_back(node->left);
                newLvlArr.push_back(node->right);
            }
            // check this level
            if (!checkSymmetric(newLvlArr)) {
                return false;
            }
            if (!newLvl.empty()) {
                lvlOrderTree.push(newLvl);
            }
        }
        
        return true;
    }
};


#endif /* easy_SymmetricTreeMMMRecurItera_h */
