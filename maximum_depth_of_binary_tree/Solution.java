import NormalClass.TreeNode;

/**
 * Created by luxy on 6/25/16.
 */
public class MaximumDepthofBT {
    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
    }
}

