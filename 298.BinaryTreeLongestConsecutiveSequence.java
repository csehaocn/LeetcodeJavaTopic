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
    
    public int longestConsecutiveAux(TreeNode root, int pVal, int pLen){
        
        int nextLen = 0;
        if( pVal+1 == root.val ){
            nextLen = pLen+1;
        }else{
            nextLen = 1;
        }
        
        int ret = Math.max(nextLen, pLen);
        
        if(null != root.left){
            int l = longestConsecutiveAux(root.left, root.val, nextLen);
            // Error: the update of nextLen here influenced the next update on the right.
            //nextLen = Math.max(l, nextLen);
            ret = Math.max(l, ret);
        }
        
        if(null != root.right){
            int r = longestConsecutiveAux(root.right, root.val, nextLen);
            //nextLen = Math.max(r, nextLen);
            ret = Math.max(r, ret);
        }

        return ret;
    }
    
    public int longestConsecutive(TreeNode root) {
        if(null == root)
            return 0;
        
        return longestConsecutiveAux(root, root.val, 1);
    }
}
