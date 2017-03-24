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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(null == p && null == q){
            return true;
        }
        
        if(null == p || null == q){
            return false;
        }
        
        // Error: forgot p.val == q.val..
        if(p.val != q.val)
            return false;
        else
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        
    }
}
