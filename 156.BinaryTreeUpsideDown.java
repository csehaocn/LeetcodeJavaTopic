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
    
    class Pair{
        TreeNode m_f;
        TreeNode m_s;
        Pair(TreeNode f, TreeNode s){
            this.m_f = f;
            this.m_s = s;
        }
    }
    
    public Pair upsideDownBinaryTreeAux(TreeNode root){
    
        if(null == root)
            return null;
        
        if(null == root.left && null == root.right){
            return new Pair(root, root);
        }
        
        TreeNode r = root;
        TreeNode l = root.left;
            
        Pair lret = upsideDownBinaryTreeAux(l);
        lret.m_s.right = r;
        lret.m_s.left = r.right;
        r.right = null;
        r.left = null;
        //Error: was going to clear the value for children of r.right, but set the wrong place,
        //This problem is very confusing, better go with actuall example
        //l.right = null;
        //l.left = null;
        
        return new Pair(lret.m_f, r);

    }
    
    
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        
        if(null == root)
            return null;
        
        Pair ret = upsideDownBinaryTreeAux(root);
        return ret.m_f;
        
    }
}
