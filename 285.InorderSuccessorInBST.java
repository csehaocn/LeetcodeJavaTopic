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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if(null == root)
            return null;
        if(p.val > root.val){
            return inorderSuccessor(root.right, p);
        }else if(p.val == root.val){
            // Here is a trick that include several situatoins, p is not really included in the right sub tree
            // But the same function can be used to find its successor still. 
            return inorderSuccessor(root.right, p);
        }else{
            // p.val < root.val
            TreeNode l = inorderSuccessor(root.left, p);
            if(null == l){
                return root;
            }else{
                return l;
            }
        }
    }
}
