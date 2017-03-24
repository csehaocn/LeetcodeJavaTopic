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
    
    class retObj{
        
        int c;
        boolean u;
        int v;
        
        public retObj(int c, boolean u, int v){
            this.c = c;
            this.u = u;
            this.v = v;
        }
    }
    
    public retObj countUnivalSubtreesAux(TreeNode root){
        // None null root
        int count = 0;
        
        boolean uniform = true;
        
        if(null != root.left){
            retObj l = countUnivalSubtreesAux(root.left);
            if(false == l.u || l.v != root.val)
                uniform = false;
            count += l.c;
        }

        if(null != root.right){
            retObj r = countUnivalSubtreesAux(root.right);
            if(false == r.u || r.v != root.val)
                uniform = false;
            count += r.c;
        }
        //System.out.println(count + " " + uniform);
        if(uniform){
            return new retObj(count+1, uniform, root.val);
        }else{
            return new retObj(count, uniform, root.val);
        }
        
    }
    
    public int countUnivalSubtrees(TreeNode root) {
        if(null == root)
            return 0;
        retObj r = countUnivalSubtreesAux(root);
        return r.c;
    }
}
