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
    
    private void expandResList(int i, List<List<Integer>> res){
        while(res.size() <= i){
            res.add(new ArrayList<Integer>());
        }
        
        return;
    }
    
    public int findLeavesAux(TreeNode root, List<List<Integer>> res){
        if(null == root.left && null == root.right){
            expandResList(0, res);
            res.get(0).add(root.val);
            return 0;
        }
        
        int l = 0;
        
        if(null != root.left)
            l = findLeavesAux(root.left, res);
            
        int r = 0;
        
        if(null != root.right)
            r = findLeavesAux(root.right, res);
            
        // Error: int i = Math.max(l, r);
        // Forgot should increase 1;
        int i = Math.max(l, r) + 1;
        
        expandResList(i, res);
        res.get(i).add(root.val);
        
        return i;
        
    }
    
    public List<List<Integer>> findLeaves(TreeNode root) {
        
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        if(null == root)
            return res;
            
        findLeavesAux(root, res);
        
        return res;
        
    }
}
