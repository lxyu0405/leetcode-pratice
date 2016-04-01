#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};

class Tree {
public:
    int getDis(TreeNode* root) {
        // write code here
        if (root == NULL) {
            return -1;
        }
        int max = root->val;
        int min = root->val;
        getMaxMin(root, max, min);
        
        vector<int> maxRoute;
        getRoute(maxRoute, max, root);
        vector<int> minRoute;
        getRoute(minRoute, min, root);
        
        return getDisByRoute(maxRoute, minRoute);
    }
    
    int getDisByRoute(vector<int>& maxRoute, vector<int>& minRoute){
        for (int i = 0; i < maxRoute.size(); i++) {
            for (int j = 0; j < minRoute.size(); j++) {
                if (maxRoute[i] == minRoute[j]) {
                    return i+j;
                }
            }
        }
        return -1;
    }
    
    void getMaxMin(TreeNode* node, int& max, int& min){
        if (node == NULL) {
            return;
        }
        if (node->val > max && node->right == NULL && node->left == NULL) {
            max = node->val;
        }
        if (node->val < min && node->right == NULL && node->left == NULL) {
            min = node->val;
        }
        getMaxMin(node->left, max, min);
        getMaxMin(node->right, max, min);
    }
    
    bool getRoute(vector<int>& route, int target, TreeNode* root){
        if (root == NULL) {
            return false;
        }
        if (root->val == target) {
            route.push_back(target);
            return true;
        }
        if (getRoute(route, target, root->left)) {
            route.push_back(root->val);
            return true;
        }else if (getRoute(route, target, root->right)){
            route.push_back(root->val);
            return true;
        }else{
            return false;
        }
    }
    
    void printRoute(vector<int>& route){
        for (int i = 0; i < route.size(); i++) {
            cout << route[i] << " ";
        }
        cout << endl;
    }
    
};
int main(int argc, const char * argv[]) {
    int nums[] = {34,19,45,22,29,31,35,36,4,17,2,24,28,14,20,13,30,12,25,9,1,8,37,42,3,23,11,7,6,10,5,21,26,38,44,27,32,15,18,41,40,39,43,16,33};
    vector<int> vecNums(nums,nums+sizeof(nums)/sizeof(int));
    vector<TreeNode*> tree(vecNums.size(), NULL);
    tree[0] = new TreeNode(nums[0]);
    for (int i = 1; i < vecNums.size(); i++) {
        TreeNode* node = new TreeNode(vecNums[i]);
        if (i & 1) { // odd
            tree[(i-1)>>1]->left = node;
        }else{ // even
            tree[(i-1)>>1]->right = node;
        }
        tree[i] = node;
    }
    
    Tree test;
    cout << test.getDis(tree[0]) << endl;
    return 0;
}
