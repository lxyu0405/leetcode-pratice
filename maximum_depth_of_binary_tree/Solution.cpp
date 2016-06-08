struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
