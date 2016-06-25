import NormalClass.TreeNode;

/**
 * Created by luxy on 6/25/16.
 *
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class MinimumDepthofBT {
    public int minDepth(TreeNode root) {
        if (root == null)
            return 0;
        int leftDepth = minDepth(root.left);
        int rightDepth = minDepth(root.right);

        if (leftDepth == 0 && rightDepth == 0)  return 1;
        if (leftDepth == 0)     return rightDepth + 1;
        if (rightDepth == 0)    return leftDepth + 1;

        return (leftDepth < rightDepth) ? leftDepth + 1 : rightDepth + 1;
    }
    private int minDepthCore(TreeNode node){
        if (node == null)
            return 0;
        int leftDepth = minDepth(node.left);
        int rightDepth = minDepth(node.right);
        return (leftDepth < rightDepth) ? leftDepth + 1 : rightDepth + 1;
    }
}

