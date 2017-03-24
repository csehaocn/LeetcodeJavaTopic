/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    public boolean isMirror(TreeNode left, TreeNode right){
        if(null == left && null == right)
            return true;
        if(null == left || null == right)
            return false;
        if(left.val != right.val)
            return false;
        return isMirror(left.left, right.right) && isMirror(left.right, right.left);
    }
    
    public boolean isSymmetric(TreeNode root) {
        if(null == root)
            return true;
        return isMirror(root.left, root.right);
    }
}

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/*
Iterative solution, basically, iterative traversal of two subtrees at the same time, 
1.	Duplicated code for left and right sub trees.
2. 	Added few more line of codes for equality. Especially note the quit condition. 
3.	Traversal primarily on one side while matching on the other side is another solution.
*/
public class Solution {
    
    public boolean isSymmetric(TreeNode root) {
        if(null == root)
            return true;
        if(null == root.left && null == root.right)
            return true;
        if(null == root.left || null == root.right)
            return false;
            
        Stack<TreeNode> leftS = new Stack<>();
        Stack<TreeNode> rightS = new Stack<>();
        
        TreeNode leftIt = root.left;
        TreeNode rightIt = root.right;
        
        while( (!leftS.isEmpty() || null != leftIt) && (!rightS.isEmpty() || null != rightIt) ){
            
            if(null == leftIt && null == rightIt){
                leftIt = leftS.pop().right;
                rightIt = rightS.pop().left;
                continue;
            }
            
            if(null == leftIt && null != rightIt || null == rightIt && null != leftIt)
                return false;
            
            if(leftIt.val != rightIt.val)
                return false;
            
            leftS.push(leftIt);
            rightS.push(rightIt);
            
            leftIt = leftIt.left;
            rightIt = rightIt.right;
            
        }
        
        // Error: Quit loop does not means they are eventually equal.
        return leftS.isEmpty() && rightS.isEmpty() && leftIt == rightIt;
        
    }
}
