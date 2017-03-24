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
    public int closestValue(TreeNode root, double target) {
        if(null == root)
            return 0;
            
        int res = root.val;
        
        if(null != root.left){
            int l = closestValue(root.left, target);
            if(Math.abs(l - target) < Math.abs(res - target))
                res = l;
        }
        
        if(null != root.right){
            int r = closestValue(root.right, target);
            if(Math.abs(r - target) < Math.abs(res - target))
                res = r;
        }
           
        return res;    
    }
}
